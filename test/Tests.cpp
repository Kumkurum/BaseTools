//
// Created by andrey on 05.10.23.
//
#include "Tests.h"
#include "../include/BaseTools/ByteArray.h"
#include "../include/BaseTools/Debug.h"
#include <string>
using namespace BaseTools;
TEST(Test_ByteArray, 0) {
    ByteArray bytes("s",1) ;
    auto bytes2 ( std::move (bytes ) ) ;
    bytes = std::move (bytes2 ) ;
}

TEST(Test_ByteArray, 1) {
    std::string str{"TEST"};
    ByteArray bytes(str.data(), 4);
    EXPECT_STREQ(str.data(), bytes.dataChar());
    EXPECT_TRUE(true);
}
TEST(Test_ByteArray, 2) {

    ByteArray bytes1("test", 4);
    EXPECT_STREQ(bytes1.dataChar(),"test");
    ByteArray bytes2("plus", 4);
    EXPECT_STREQ(bytes2.dataChar(),"plus");
    std::string strResul = std::string(bytes1.dataChar()) + std::string(bytes2.dataChar());
    EXPECT_STREQ(strResul.data(),"testplus");
    auto newByte = bytes1 + bytes2;
    EXPECT_STREQ(strResul.data(), newByte.dataChar());

    newByte = bytes1 + ByteArray{"plus", 4};
    EXPECT_STREQ(strResul.data(), newByte.dataChar());
}
TEST(Test_ByteArray, 3) {
    ByteArray bytes1("JJFFAA123", 14);
    std::cout<<bytes1.dataChar();
    EXPECT_TRUE(true);
}

TEST(Test_ByteArray, 4) {
    ByteArray bytes("Hello World!", 12);
    bytes[1] = std::byte('I');
    Log()<<bytes.data();
    EXPECT_STREQ("HIllo World!", bytes.dataChar());
    EXPECT_TRUE(true);
}

TEST(Test_ByteArray, 5) {
    ByteArray bytes("Hello World!", 12);
    bytes.append(std::byte('&'));
    EXPECT_STREQ("Hello World!&", bytes.dataChar());
    bytes.append(std::byte('q'));
    bytes.append(std::byte('w'));
    bytes.append(std::byte('e'));
    bytes.append(std::byte('r'));
    bytes.append(std::byte('t'));
    bytes.append(std::byte('y'));
    EXPECT_STREQ("Hello World!&qwerty", bytes.dataChar());
}

TEST(Test_ByteArray, 6) {
    ByteArray bytes("Hello World!", 12);
    uint64_t number{0};
    number |= uint64_t ('W');
    number |= uint64_t ('O')<<56;
    number |= uint64_t ('R')<<48;
    number |= uint64_t ('L')<<40;
    number |= uint64_t ('D')<<32;
    number |= uint64_t ('S')<<24;
    bytes.append(number);
    EXPECT_STREQ("Hello World!WORLDS", bytes.dataChar());
}

TEST(Test_ByteArray, 7) {
    ByteArray bytes{"",0};
    uint64_t number{0};
    number |= uint64_t ('W');
    number |= uint64_t ('O')<<56;
    number |= uint64_t ('R')<<48;
    number |= uint64_t ('L')<<40;
    number |= uint64_t ('D')<<32;
    number |= uint64_t ('S')<<24;
    bytes.append(number);
    bytes.reserve(8);
    EXPECT_STREQ("WORLDS", bytes.dataChar());
}

void foo(const ByteArray& data){
    int i(data.size());
}
void foo1(const ByteArray&& data){
    int i(data.size());
}

TEST(Test_ByteArray, 8) {
    ByteArray bytes{"WORLD",5};
//    EXPECT_TRUE(std::byte('W')== bytes[0]);
    ByteArray newBytes{std::move(bytes)};
//    EXPECT_EQ(bytes.size(), 0);
    EXPECT_EQ(newBytes.size(), 5);
    ByteArray newBytes1 = std::move(newBytes);
//    EXPECT_EQ(newBytes.size(), 0);//IAA невалидный указатель
    EXPECT_EQ(newBytes1.size(), 5);
    const ByteArray constByte{"HELLO",5 };
    ByteArray fromConstByte(constByte);
    ByteArray sss{"asdasd",6 };
    foo(fromConstByte);
    foo1(std::move(sss));
//    EXPECT_EQ(sss.size(), 6);
    EXPECT_EQ(newBytes1.size(), 5);
}
TEST(Test_ByteArray, 9) {
    ByteArray bytes{"WORLD"};
}

TEST(Test_Debug, 0) {
    std::string testString{"sadasd"};
    Log(COLOR::Black)<<"COLOR"<<"color"<<123<<testString<<__LINE__<<__FUNCTION__ ;
    Log(COLOR::Red)<<"COLOR"<<"color"<<"color"<<123<<testString;
    Log(COLOR::Green)<<"COLOR"<<"color"<<__LINE__<<__FUNCTION__;
    Log(COLOR::Yellow)<<"COLOR"<<"color";
    Log(COLOR::Blue)<<"COLOR"<<"color";
    Log(COLOR::Magenta)<<"COLOR"<<"color";
    Log(COLOR::Cyan)<<"COLOR"<<"color";
    Log(COLOR::White)<<"COLOR"<<"color";
    Log().setSeparator('\n');
    Log(COLOR::Bright_Black)<<"COLOR"<<"color";
    Log(COLOR::Bright_Red)<<"COLOR"<<"color";
    Log(COLOR::Bright_Green)<<"COLOR"<<"color";
    Log().setSeparator('-');
    Log(COLOR::Bright_Yellow)<<"COLOR"<<"color";
    Log().setSeparator('\t');
    Log(COLOR::Bright_Blue)<<"COLOR"<<"color";
    Log()<<"COLOR"<<"color";
    Log()<<"COLOR"<<"color";
    Log()<<"COLOR"<<"color"<<"color"<<"color"<<"color";

    EXPECT_TRUE(true);

}

#include <thread>
TEST(Test_Debug, 1) {
    Log(COLOR::Bright_Green)<<"COLOR"<<"col123or";
    Log()<<("COLOR","c123olor", "co12312lor");
    std::chrono::milliseconds timespan(201);
    std::this_thread::sleep_for(timespan);
    Log()<<"COLOR"<<"col123123or"<<123;

    std::this_thread::sleep_for(timespan);
    Log()<<"COLOR"<<"col2w22or"<<123;

    std::this_thread::sleep_for(timespan);
    Log()<<"COLOR"<<"aaaa"<<123;

    std::this_thread::sleep_for(timespan);
    Log()<<"COLOR"<<"asdasd"<<123;
    EXPECT_TRUE(true);
}
#include "../include/BaseTools/BitSet64.h"
TEST(Test_BitSet64, 0) {
    ByteArray test{"alekos",6};
    BitSet64 bits(test.data(),test.size());
    Log()<<bits;
    char string[8];
    bits.toChar(string);
    Log()<<string;
    EXPECT_TRUE(true);
}

TEST(Test_BitSet64, 1) {
    ByteArray test{"alekos",6};
    BitSet64 bits(test.data(),test.size());
    Log()<<bits[0];
    char string[8];
    bits.toChar(string);
    Log()<<string;
    EXPECT_TRUE(true);
}

#include "../include/BaseTools/Dijkstra.h"


TEST(Algorithmic, Dijkstra){
    Algorithmic::Dijkstra a;
    a.append("Earth", "Moon", 10000);
    a.append("Earth", "Mars", 300);
    a.append("Earth", "Mercury", 400);
    a.append("Earth", "K", 10);
    a.append("K", "L", 100);
    a.append("L", "M", 100);
    a.append("M", "N", 100);
    a.append("N", "O", 100);
    a.append("O", "P", 100);
    a.append("P", "R", 100);
    a.append("R", "S", 100);
    a.append("S", "T", 100);
    a.append("T", "F", 100);
    a.append("F", "Venera", 10);

    a.append("Moon", "Earth", 150);
    a.append("Moon", "Mercury", 300);
    a.append("Moon","Venera", 10000);
    a.append("Moon","Mars", 100);

    a.append("Mars", "Earth", 700);
    a.append("Mars", "Moon", 50);
    a.append("Mars", "Neptune", 600);

    a.append("Venera", "Jupyter", 50);
    a.append("Venera", "Pluto", 50);

    a.append("Mercury", "Mars", 100);
    a.append("Mercury", "Jupyter", 100);

    a.append("Jupyter", "Mercury", 100);
    a.append("Jupyter", "Mars", 100);

    a.append("Neptune", "Titan", 100);

    a.append("Titan", "Venera", 100);

    a.append("Pluto", "Mars", 300);
    a.append("Pluto", "Neptune", 100);
    a.append("Pluto", "Jupyter", 100);

    auto path = a.findPath("Earth", "Pluto");
    std::list<std::string> EQResult;
    EQResult.push_back("Pluto");
    EQResult.push_back("Venera");
    EQResult.push_back("F");
    EQResult.push_back("T");
    EQResult.push_back("S");
    EQResult.push_back("R");
    EQResult.push_back("P");
    EQResult.push_back("O");
    EQResult.push_back("N");
    EQResult.push_back("M");
    EQResult.push_back("L");
    EQResult.push_back("K");
    EQResult.push_back("Earth");
    uint32_t  totalCost{};
    auto EQPtr = EQResult.begin();
    for(auto& node: path){
        EXPECT_STREQ(EQPtr->c_str(), node->_name.c_str());
        totalCost+=node->_cost;
        ++EQPtr;
    }
    EXPECT_EQ(totalCost, 970);

}

TEST(Algorithmic, Dijkstra2){
    Log()<<"C++"<<__cplusplus;
    Algorithmic::Dijkstra a;
    a.append("Earth", "Moon", 100);///////////////////////////// CHANGE
    a.append("Earth", "Mars", 300);
    a.append("Earth", "Mercury", 400);
    a.append("Earth", "K", 10);
    a.append("K", "L", 100);
    a.append("L", "M", 100);
    a.append("M", "N", 100);
    a.append("N", "O", 100);
    a.append("O", "P", 100);
    a.append("P", "R", 100);
    a.append("R", "S", 100);
    a.append("S", "T", 100);
    a.append("T", "F", 100);
    a.append("F", "Venera", 10);

    a.append("Moon", "Earth", 150);
    a.append("Moon", "Mercury", 300);
    a.append("Moon","Venera", 100);///////////////////////////// CHANGE
    a.append("Moon","Mars", 100);

    a.append("Mars", "Earth", 700);
    a.append("Mars", "Moon", 50);
    a.append("Mars", "Neptune", 600);

    a.append("Venera", "Jupyter", 50);
    a.append("Venera", "Pluto", 50);

    a.append("Mercury", "Mars", 100);
    a.append("Mercury", "Jupyter", 100);

    a.append("Jupyter", "Mercury", 100);
    a.append("Jupyter", "Mars", 100);

    a.append("Neptune", "Titan", 100);

    a.append("Titan", "Venera", 100);

    a.append("Pluto", "Mars", 300);
    a.append("Pluto", "Neptune", 100);
    a.append("Pluto", "Jupyter", 100);

    auto path = a.findPath("Earth", "Pluto");
    std::list<std::string> EQResult;
    EQResult.push_back("Pluto");
    EQResult.push_back("Venera");
    EQResult.push_back("Moon");
    EQResult.push_back("Earth");
    uint32_t  totalCost{};
    auto EQPtr = EQResult.begin();
    for(auto& node: path){
        EXPECT_STREQ(EQPtr->c_str(), node->_name.c_str());
        totalCost+=node->_cost;
        ++EQPtr;
    }
    EXPECT_EQ(totalCost, 250);

}