//
// Created by andrey on 08.02.24.
//

#include "../include/BaseTools/BitSet64.h"
#include "../include/BaseTools/Debug.h"
#include <bitset>
namespace BaseTools {
    BitSet64::BitSet64(const std::byte *byte, int size) {
        if (size >= 8) {
            for (auto i{0}; i < 8; ++i)
                for (auto j{0}; j < 8; ++j)
                    _bits |= static_cast<uint64_t>(static_cast<unsigned char>(byte[i] >> j) & 1) << ((7-i) * 8 + (j));
        } else {
            for (auto i{0}; i < size; ++i)
                for (auto j{0}; j < 8; ++j)
                    _bits |= static_cast<uint64_t>(static_cast<unsigned char>(byte[i] >> j) & 1) << ((size - 1 - i) * 8 + (j));
        }
    }

    bool BitSet64::operator[](size_t index) {
        return (_bits>>(index)) & 1;
    }

    BitSet64::BitSet64(uint64_t bits):_bits{bits} {}

    Impl_Temp &&operator<<(Impl_Temp &&tmp, BitSet64 &bitSet64) {
        std::bitset<64> tmpBits{bitSet64._bits};
        for(auto i{0}; i < 64; ++i){
            tmpBits[i] = (bitSet64._bits>>(i)) & 1;
        }
        tmp._logger->_stream << tmpBits;
        return std::move(tmp);
    }

    Impl_Temp &&operator<<(Impl_Temp &&tmp, BitSet64 &&bitSet64) {
        tmp._logger->_stream << bitSet64._bits;
        return std::move(tmp);
    }
    void BitSet64::toChar(char* ptr) const {
        for(int i{0}; i < 8; ++i)
            ptr[7 - i] = _bits>>8*i;
    }
}
