//
// Created by andrey on 28.11.23.
//

#ifndef BASETOOLS_DEBUG_H
#define BASETOOLS_DEBUG_H

#include <iostream>
namespace BaseTools {
    enum class COLOR{
        None           = 0,
        Disable        = 1,
        Black          = 30,
        Red            = 31,
        Green          = 32,
        Yellow         = 33,
        Blue           = 34,
        Magenta        = 35,
        Cyan           = 36,
        White          = 37,
        Bright_Black   = 90,
        Bright_Red     = 91,
        Bright_Green   = 92,
        Bright_Yellow  = 93,
        Bright_Blue    = 94,
        Bright_Magenta = 95,
        Bright_Cyan    = 96,
        Bright_White   = 97
    };
    class Impl_Temp;
    class BitSet64;
    class Impl_Logger{
        Impl_Logger();
        std::ostream _stream;
        COLOR _color;
        double _timeStart;
        char _separator;
        char _endLine;
        template<typename T>
        friend Impl_Temp&& operator<<(Impl_Temp&& tmp,T&& text);
        friend Impl_Temp&& operator<<(Impl_Temp&& tmp,BitSet64&& bitSet64);
        friend Impl_Temp &&operator<<(Impl_Temp && tmp, BitSet64& bitSet64);
        friend Impl_Temp Log(COLOR color);
        friend Impl_Temp;
    };


    class Impl_Temp{
    public:
        Impl_Temp(Impl_Logger* stream);
        ~Impl_Temp();
        void setSeparator(char);
        void setEndLine(char);

        template<typename T>
        friend Impl_Temp&& operator<<(Impl_Temp&& tmp,T&& text);
        friend Impl_Temp&& operator<<(Impl_Temp&& tmp,BitSet64&& bitSet64);
        friend Impl_Temp &&operator<<(Impl_Temp && tmp, BitSet64& bitSet64);
    private:
        Impl_Logger* _logger;
    };
    template<typename T>
    Impl_Temp&& operator<<(Impl_Temp&& tmp,T&& text){
//#ifdef DEBUG
        tmp._logger->_stream<<std::forward<T>(text)<<tmp._logger->_separator;
//#endif
        return std::move(tmp);
    }
    Impl_Temp Log(COLOR color = COLOR::None);
}
#endif //BASETOOLS_DEBUG_H
