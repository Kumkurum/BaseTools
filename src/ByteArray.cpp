//
// Created by andrey on 03.11.23.
//

#include "../include/BaseTools/ByteArray.h"
#include "Impl_ByteArray.h"
#include "../include/BaseTools/Debug.h"
namespace BaseTools {
    ByteArray::ByteArray(char *data, std::size_t size): _pImpl(std::make_unique<Impl_ByteArray>(reinterpret_cast<std::byte*>(data), size)){
    }

    ByteArray::ByteArray(char symbol, std::size_t size): _pImpl(std::make_unique<Impl_ByteArray>(symbol, size)){
    }

    ByteArray::~ByteArray() = default;
    ByteArray::ByteArray(ByteArray &&_rhs)noexcept{
        _pImpl = std::move(_rhs._pImpl);
        _rhs._pImpl = std::make_unique<Impl_ByteArray>();
    }
    ByteArray &ByteArray::operator=(ByteArray &&_rhs)noexcept= default;

    ByteArray::ByteArray(const ByteArray &_rhs)//глубокое копирование
            : _pImpl(nullptr){
        if(_rhs._pImpl)
            _pImpl = std::make_unique<Impl_ByteArray>(*_rhs._pImpl);
    }

    ByteArray &ByteArray::operator=(const ByteArray &_rhs){//глубокое копирование
        if(!_rhs._pImpl) _pImpl.reset();
        else if(!_pImpl) _pImpl = std::make_unique<Impl_ByteArray> (*_rhs._pImpl);
        else *_pImpl = *_rhs._pImpl;
        return *this;
    }

    std::byte *ByteArray::data()const {
        return _pImpl->data();
    }

    std::size_t ByteArray::size()const {
        return _pImpl->size();
    }

    ByteArray ByteArray::operator+(ByteArray &&_rhs) {
        ByteArray array(' ', 0);
        array._pImpl.reset( static_cast<Impl_ByteArray*>(_pImpl.get())->operator+(static_cast<Impl_ByteArray*>(_rhs._pImpl.get())));
        return array;
    }

    ByteArray ByteArray::operator+(ByteArray &_rhs) {
        ByteArray array(' ', 0);
        array._pImpl.reset( static_cast<Impl_ByteArray*>(_pImpl.get())->operator+(static_cast<Impl_ByteArray*>(_rhs._pImpl.get())));
        return array;
    }

    std::byte& ByteArray::operator[](std::size_t index) {
        return _pImpl->operator[](index);
    }

    char *ByteArray::dataChar() {
        return _pImpl->dataChar();
    }

    void ByteArray::append(uint64_t part) {
        _pImpl->append(part);
    }

    void ByteArray::append(std::byte symbol) {
        _pImpl->append(symbol);
    }

    void ByteArray::reserve(size_t size) {
        _pImpl->reserve(size);
    }
}

