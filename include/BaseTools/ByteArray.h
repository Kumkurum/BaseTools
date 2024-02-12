//
// Created by andrey on 03.11.23.
//

#ifndef BASETOOLS_BYTEARRAY_H
#define BASETOOLS_BYTEARRAY_H
#include <memory>
#include "cstddef"
namespace BaseTools {
    class Impl_Temp;
    class ByteArray {
    public:
        ByteArray(char* data = nullptr, std::size_t size = 0);
        ByteArray(char symbol, std::size_t size = 1);
        ~ByteArray();
        ByteArray(const ByteArray &_rhs);
        ByteArray &operator=(const ByteArray &_rhs);
        ByteArray(ByteArray &&_rhs) noexcept ;
        ByteArray &operator=(ByteArray &&_rhs) noexcept ;

        //Тут далее интерфейсы для юзабилити
        //interface
        ByteArray operator+(ByteArray &&_rhs);
        ByteArray operator+(ByteArray &_rhs);
        void append(uint64_t part);
        void append(std::byte symbol);
        void reserve(size_t size);
        [[nodiscard]] std::byte* data()const;
        /**
         * ОСТОРОЖНО! Возвражает коппию сырых данных! Возможно утечка!
         * @return  char* массив
         */
        char* dataChar();
        [[nodiscard]] std::size_t size()const;
        std::byte& operator[](std::size_t  index);
    private:
        struct Impl_ByteArray;
        std::unique_ptr<Impl_ByteArray> _pImpl;
    };
}
#endif //BASETOOLS_BYTEARRAY_H
