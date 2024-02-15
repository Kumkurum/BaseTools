//
// Created by andrey on 03.11.23.
//

#ifndef BASETOOLS_BYTEARRAY_H
#define BASETOOLS_BYTEARRAY_H
#include <memory>
#include "cstddef"
namespace BaseTools {
    class Impl_Temp;
    /**
     * Класс для работы с массивом байт
     * Поддерживает базовые операции
     * использует pImpl и RTTI управление памятью
     */
    class ByteArray {
    public:
        explicit ByteArray(const char* data);

        explicit ByteArray(const char* data, std::size_t size);
        explicit ByteArray(char symbol, std::size_t size = 1);
        ~ByteArray();
        ByteArray(const ByteArray &_rhs);
        ByteArray &operator=(const ByteArray &_rhs);
        ByteArray(ByteArray &&_rhs) noexcept ;
        ByteArray &operator=(ByteArray &&_rhs) noexcept ;

        //Тут далее интерфейсы для юзабилити
        //interface
        ByteArray operator+(ByteArray &&_rhs);
        ByteArray operator+(ByteArray &_rhs);
        /**
         * Вставка 8-байтного куска
         * @param part -8 байт данных
         */
        void append(uint64_t part);
        /**
         * вставка байта
         * @param symbol - байт данных
         */
        void append(std::byte symbol);
        /**
         * Выделение блока памяти, что бы не приходилось расширять массив при каждом добавлении байта
         * @param size - размер выделенной памяти
         */
        [[deprecated]] void reserve(size_t size);
        /**
         * Прямой доступ к данным
         * Стоит пользоваться с аккуратностью сырой указатель на данные!
         * @return указатель на блок данных
         */
        [[nodiscard]] std::byte* data()const;
        /**
         * ОСТОРОЖНО! Возвражает коппию сырых данных! Возможно утечка!
         * @return  char* сырой указатель на данные
         */
        [[nodiscard]] char* dataChar();
        [[nodiscard]] std::size_t size()const;
        std::byte& operator[](std::size_t  index);
    private:
        struct Impl_ByteArray;
        std::unique_ptr<Impl_ByteArray> _pImpl;
    };
}
#endif //BASETOOLS_BYTEARRAY_H
