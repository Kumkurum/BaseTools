//
// Created by andrey on 28.11.23.
//
#include "../include/BaseTools/Debug.h"
#include <chrono>
#include <cmath>
namespace BaseTools {
    inline double getTime() {
        return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000;
    }
    Impl_Logger::Impl_Logger():_stream{std::cout.rdbuf()}, _color{COLOR::Green}, _separator{'\t'}, _endLine{'\n'}{
        _timeStart = getTime();
    }

    Impl_Temp Log(COLOR color) {
        static Impl_Logger loger;
        if(color != COLOR::None)
            loger._color = color;
        Impl_Temp tmp(&loger);
        return tmp;
    }

    void Impl_Temp::setSeparator(char separator) {
        _logger->_separator = separator;
    }
    Impl_Temp::Impl_Temp(Impl_Logger *logger) :_logger{logger}{
        _logger->_stream<<"\033[1;"<<static_cast<int>(logger->_color)<<"m["<<round((getTime() - _logger->_timeStart)*1000)/1000<<"]::";
    }
    Impl_Temp::~Impl_Temp() {
        _logger->_stream<<"\033[1;0m"<<_logger->_endLine;
    }

    void Impl_Temp::setEndLine(char endLine) {
        _logger->_endLine = endLine;
    }
}

__attribute__((constructor)) void description() {
#ifndef NO_DESCRIPTION
    BaseTools::Log(BaseTools::COLOR::Bright_Cyan)<<"Это готовые базовые кирпичики из которых можно строить более сложные приложения";
    BaseTools::Log(BaseTools::COLOR::Cyan)<<"Разработка велась пользователем Kumkurum!";
#endif
}