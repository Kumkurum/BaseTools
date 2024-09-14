//
// Created by andrey on 11.09.24.
//

#ifndef BASETOOLS_SIGNAL_H
#define BASETOOLS_SIGNAL_H
#include <memory>

struct EmptyType{};
class NullType{};

template <typename R>
struct FunctorImplBase{
    typedef R ResultType;
    typedef EmptyType Parm1;
    typedef EmptyType Parm2;
    typedef EmptyType Parm3;
    typedef EmptyType Parm4;
    virtual ~FunctorImplBase(){}
};

template<typename R, typename T1=NullType, typename T2=NullType>
class FunctorImpl;

template < typename R>
class FunctorImpl<R>: public FunctorImplBase<R>{
public:
    typedef R ResultType;
    virtual R operator()() = 0;
};

template < typename R, typename T1>
class FunctorImpl<R,T1>: public FunctorImplBase<R>{
public:
    typedef R ResultType;
    typedef T1 Parm1;
    virtual R operator()(T1) = 0;
};

template < typename R, typename T1, typename T2>
class FunctorImpl: public FunctorImplBase<R>{
public:
    typedef R ResultType;
    typedef T1 Parm1;
    typedef T2 Parm2;
    virtual R operator()(T1, T2) = 0;
};

template < class ParentFunctor, typename PointerToObj, typename PointerToMemFn>
class MemFunHandler : public FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::Parm1, typename ParentFunctor::Parm2>{
    typedef typename ParentFunctor::Impl Base;
public:
    typedef typename ParentFunctor ::ResultType ResultType;
    typedef typename Base::Parm1 Parm1;
    typedef typename Base::Parm2 Parm2;

    MemFunHandler(const PointerToObj& pObj, PointerToMemFn pFunc):
            _pObj{pObj}, _pFunc{pFunc}{}

    ResultType operator()() {
        return ((*_pObj).*_pFunc)();
    }

    ResultType operator()(Parm1 p1){
        return ((*_pObj).*_pFunc)(p1);
    }

    ResultType operator()(Parm1 p1, Parm2 p2){
        return ((*_pObj).*_pFunc)(p1, p2);
    }
private:
    PointerToObj _pObj;
    PointerToMemFn _pFunc;
};

template <typename R = void, typename T1 = NullType, typename T2=NullType>
class Functor{
public:
    typedef R ResultType;
    typedef FunctorImpl<R, T1, T2> Impl;
    typedef T1 Parm1;
    typedef T2 Parm2;

    template <class PtrObj, typename MemFn>
    Functor(const PtrObj& p, MemFn memFn)
            : _handler{new MemFunHandler<Functor, PtrObj, MemFn>  (p, memFn)}
    {};

    Functor() : _handler{nullptr}
    {}

    ResultType operator()()const{
        return (*_handler)();
    }

    ResultType operator()(Parm1 p1) const{
        return (*_handler)(p1);
    }

    ResultType operator()(Parm1 p1, Parm2 p2) const{
        return (*_handler)(p1, p2);
    }
private:
    std::unique_ptr<Impl> _handler;
};
#endif //BASETOOLS_SIGNAL_H
