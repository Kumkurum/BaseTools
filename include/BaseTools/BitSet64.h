//
// Created by andrey on 08.02.24.
//

#ifndef BASETOOLS_BITSET64_H
#define BASETOOLS_BITSET64_H

#include <cstdint>
#include <cstddef>
#include <istream>
namespace BaseTools {
    class Impl_Temp;
    /**
     * Класс для работы с битами, хранит в себе куски по 64 бита
     * поддерживает вывод индекса и корректный вывод в Log()
     * BigEndian
     */
    class BitSet64 {
    public:
        explicit BitSet64(uint64_t bits = 0);
        BitSet64(const std::byte* byte, int size );
        /**
         * перевод 64 бит в 8 char
         * @param ptr  - указатель на массив char
         */
        void toChar(char* ptr)const;
        uint64_t _bits{0};
        /**
         * Вернёт состояние бита
         * @param index -индекс бита от 0 до 63
         * @return состояние бита
         */
        bool operator[](size_t index) const;
    };
    Impl_Temp &&operator<<(Impl_Temp && tmp, BitSet64& bitSet64);
    Impl_Temp &&operator<<(Impl_Temp && tmp, BitSet64&& bitSet64);
}


#endif //BASETOOLS_BITSET64_H
