//
// Created by andrey on 25.12.23.
//

#ifndef BASETOOLS_TREEBINARY_H
#define BASETOOLS_TREEBINARY_H
/*
#include "Debug.h"
#include <memory>
namespace BaseTools {
    template<typename T1,typename T2>
    class TreeBinary {
    public:
        TreeBinary()= default;

        void setNode(T1&& key, T2&& value){
            _size++;
            if(_root == nullptr){
                _root.reset(new Node{std::forward<T1>(key), std::forward<T2>(value)});
            }else{
                _root->setValue(std::forward<T1>(key), std::forward<T2>(value));
            }
            Log(COLOR::Green)<<"OK";
        };
        T2& find(T1 key){

            if(_root != nullptr){
                if(key == _root->_key)
                    return _root->_value;
                if(key >_root->_key){
                    if(_root->right != nullptr)
                        return _root->right->find(std::forward<T1>(key));
                    return nullptr;
                }else{
                    if(_root->left != nullptr)
                        return _root->left->find(std::forward<T1>(key));
                    return nullptr;
                }
            }
            return nullptr;
        }

        struct Node {
            Node( T1&& key, T2&& value):_key{key}, _value{value} {

            }
            T1 _key;
            T2 _value;
            Node* parent{nullptr};
            std::unique_ptr<Node> left{nullptr};
            std::unique_ptr<Node> right{nullptr};

            void setValue(T1&& key, T2&& value){
                if(key > _key){
                    if(right == nullptr){
                        right.reset(new Node{std::forward<T1>(key), std::forward<T2>(value)});
                        right->parent = this;
                    }else{
                        right->setValue(std::forward<T1>(key), std::forward<T2>(value));
                    }
                }else if(left == nullptr){
                    left.reset(new Node{std::forward<T1>(key), std::forward<T2>(value)});
                    left->parent = this;
                }else{
                    left->setValue(std::forward<T1>(key), std::forward<T2>(value));
                }
            }

            T2& find(T1 key){
                if(_key == key)
                    return _value;

            }
        };
    private:
        std::size_t _size{0};
        std::unique_ptr<Node> _root{nullptr};
    };
}
*/
#endif //BASETOOLS_TREEBINARY_H
