//
// Created by andrey on 29.08.24.
//

#include "StudyShortTest.h"
#include <string>
#include "../include/BaseTools/Debug.h"
#include "functional"
#include "../include/BaseTools/Signal.h"

using namespace BaseTools;
class Parrot
{
public:
    void Eat()
    {
        std::cout << "Ням, ням, ням ...\n";
    }
    int Speak()
    {
        std::cout << "Пиастры! Пиастры!\n";
        return 1;
    }
    void Speak1(int i)
    {
        std::cout << "Ням "<<i<<" ням, ням ...\n";
    }
    void Click(int i)
    {
        std::cout << "КЛИК "<<i<<"КЛИК ...\n";
    }
    void Speak2(int i, int x)
    {
        std::cout << "Ням "<<i<<" ням, ням ..."<<x<<"\n";
    }
};

void fuu(){
    int i{};
    i++;
    Log(COLOR::Black)<<i;
}

TEST(ConnectMetods, 0) {
    Parrot geronimo;
// Определяем два функтора
    Functor<int> cmd(&geronimo, &Parrot::Speak);
//// Вызываем каждый из них
    cmd();
    Functor<void, int> cmd1;
    cmd1 = Functor<void, int>(&geronimo, &Parrot::Speak1);
    cmd1(12);
    cmd1 = Functor<void, int>(&geronimo, &Parrot::Click);
    cmd1(1);
    Functor<void, int, int> cmd2(&geronimo, &Parrot::Speak2);
    cmd2(12, 3);
    Functor<int> cmd5;
    EXPECT_TRUE(true);
}