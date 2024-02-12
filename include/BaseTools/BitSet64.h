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
    class BitSet64 {
    public:
        BitSet64(uint64_t bits = 0);
        BitSet64(const std::byte* byte, int size );
        void toChar(char* ptr)const;
        uint64_t _bits{0};
        bool operator[](size_t index);
    };
    Impl_Temp &&operator<<(Impl_Temp && tmp, BitSet64& bitSet64);
    Impl_Temp &&operator<<(Impl_Temp && tmp, BitSet64&& bitSet64);
}


#endif //BASETOOLS_BITSET64_H
