#include <benchmark/benchmark.h>
#include <string>
#include "../include/BaseTools/ByteArray.h"



struct TestSmall{
    long x{};
    int y{};
    int z{};
};
void fooLV(BaseTools::ByteArray& testSmall){
    testSmall[0]= std::byte('0');
    testSmall[1]= std::byte('0');
    testSmall[2]= std::byte('0');
    testSmall[3]= std::byte('0');
    testSmall[4]= std::byte('0');
}

void fooRV(BaseTools::ByteArray testSmall){
    testSmall[0]= std::byte('0');
    testSmall[1]= std::byte('0');
    testSmall[2]= std::byte('0');
    testSmall[3]= std::byte('0');
    testSmall[4]= std::byte('0');
//    return testSmall;
}


static void LVFOO(benchmark::State& state) {
    for (auto _: state){
        BaseTools::ByteArray testArray{"asdasdasdasdasd", 15};
        fooLV(testArray);
    }
}


static void RVFOO(benchmark::State& state) {
    for (auto _: state) {
        BaseTools::ByteArray testArray{"asdasdasdasdasd", 15};
        fooRV(std::move(testArray));
    }

}


BENCHMARK(LVFOO); //Used to register test function
BENCHMARK(RVFOO); //Used to register test function
// Register the function as a benchmark

BENCHMARK_MAIN(); //Program entry