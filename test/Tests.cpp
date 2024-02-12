//
// Created by andrey on 05.10.23.
//
#include "Tests.h"
#include "../include/BaseTools/ByteArray.h"
#include "../include/BaseTools/Debug.h"
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
void mover(std::string &&){

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
    EXPECT_EQ(bytes.size(), 0);
    EXPECT_EQ(newBytes.size(), 5);
    ByteArray newBytes1 = std::move(newBytes);
    EXPECT_EQ(newBytes.size(), 0);
    EXPECT_EQ(newBytes1.size(), 5);
    const ByteArray constByte{"HELLO"};
    ByteArray fromConstByte(constByte);
    ByteArray sss{"asdasd",6 };
    foo(fromConstByte);
    foo1(std::move(sss));
    EXPECT_EQ(sss.size(), 6);
    EXPECT_EQ(newBytes1.size(), 5);
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
