//
// Created by andrey on 03.11.23.
//
#include <cstring>
#include "Impl_ByteArray.h"
#include <string>
#ifndef NDEBUG
#include <assert.h>
#endif
constexpr char  hex_chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
namespace BaseTools {
    ByteArray::Impl_ByteArray::Impl_ByteArray(const char symbol, std::size_t size):_size{size} {
        _buffer = new std::byte[_size];
        for(auto i{0}; i < _size; ++i)
            _buffer[i] = static_cast<std::byte>(symbol);
    }

    ByteArray::Impl_ByteArray::Impl_ByteArray(const std::byte *byteArray, std::size_t size):_size{size} {
        _buffer = new std::byte[_size];
        memcpy(_buffer, byteArray, _size);
    }

    ByteArray::Impl_ByteArray::Impl_ByteArray(const ByteArray::Impl_ByteArray &_rhs):_size{_rhs._size} {
        _buffer = new std::byte[_size];
        memcpy(_buffer, _rhs._buffer, _size);
    }

    ByteArray::Impl_ByteArray::~Impl_ByteArray() {
        delete _buffer;
    }

    ByteArray::Impl_ByteArray* ByteArray::Impl_ByteArray::operator+(const Impl_ByteArray* another) {
        auto tmp = new std::byte [_size + another->_size];
        auto* newByteArray = new ByteArray::Impl_ByteArray();
        newByteArray->_buffer = tmp;
        newByteArray->_size = _size + another->_size;
        if(_size > 1)
            memcpy(tmp, _buffer, _size);
        if(another->_size > 1)
            memcpy(tmp + _size, another->_buffer, another->_size);
        return newByteArray;
    }

    std::byte *ByteArray::Impl_ByteArray::data() {
        return _buffer;
    }

    char *ByteArray::Impl_ByteArray::dataChar() const {
        char* copy = new char[_size + 1];
        memcpy(copy, _buffer, _size);
        copy[_size] = '\0';
        return copy;
    }

    std::size_t ByteArray::Impl_ByteArray::size() const {
        return _size;
    }

    std::byte& ByteArray::Impl_ByteArray::operator[](std::size_t index) {
#ifndef NDEBUG
        assert(index >= 0 && index< _size && "Выход за границу блока данных!");
#endif
        return _buffer[index];
    }

    void ByteArray::Impl_ByteArray::append(uint64_t part) {
        auto tmp = new std::byte[_size + 8];
        memcpy(tmp, _buffer, _size);
        for(auto i{8}; i > 0; --i){
            tmp[_size++] = std::byte(part>>i*8);
        }
        delete _buffer;
        _buffer = tmp;
    }

    void ByteArray::Impl_ByteArray::append(std::byte symbol) {
        auto tmp = new std::byte[_size + 1];
        memcpy(tmp, _buffer, _size);
        tmp[_size] = symbol;
        _size++;
        delete _buffer;
        _buffer = tmp;
    }

    void ByteArray::Impl_ByteArray::reserve(std::size_t size) {
//        auto tmp = _reservedBuffer;
//        auto tmpBuffer = _buffer;
//        _reservedBuffer = operator new(size);
//        _reservedSize = size;
//        _buffer = new(_reservedBuffer) std::byte[_size];
//        memcpy(_buffer, tmpBuffer, _size);
//        operator delete(tmp);
    }
}