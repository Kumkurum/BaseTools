//
// Created by andrey on 03.11.23.
//

#ifndef CRYPTOGRAPHICLIBRARY_IMP_BYTEARRAY_H
#define CRYPTOGRAPHICLIBRARY_IMP_BYTEARRAY_H

#include "../include/BaseTools/ByteArray.h"
namespace BaseTools{
    struct ByteArray::Impl_ByteArray {
        Impl_ByteArray(char symbol, std::size_t size);
        //туплю с указателем на сырой массив, бывает ли он rvalue? вроде как да
        explicit Impl_ByteArray(const std::byte* byteArray = nullptr, std::size_t size = 0);
        Impl_ByteArray(const Impl_ByteArray& _rhs);
        ~Impl_ByteArray();

        std::byte* data();
        [[nodiscard]] char* dataChar()const;
        [[nodiscard]] std::size_t size() const;
        void append(uint64_t part);
        void append(std::byte symbol);
        void reserve(std::size_t  size);
        Impl_ByteArray* operator+(const Impl_ByteArray* another);
        std::byte& operator[](std::size_t  index);
    private:
        std::byte *_buffer;
        void* _reservedBuffer;
        std::size_t _reservedSize;
        std::size_t _size;

       [[deprecated]] void reserveBuffer();
    };
}


#endif //CRYPTOGRAPHICLIBRARY_IMP_BYTEARRAY_H
