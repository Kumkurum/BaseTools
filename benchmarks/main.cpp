#include <benchmark/benchmark.h>
#include <string>
#include "../include/BaseTools/ByteArray.h"
//#include <QtCore>
#include <vector>
using namespace std;

static void BM_arrayPlus(benchmark::State& state) {
    for (auto _ : state){
        BaseTools::ByteArray array{"append", 5};
        array = array + array;
    }
}
//BENCHMARK(BM_arrayPlus); //Used to register test function

struct TestStruct{
    int x{2};
    int y{1};
    int z{0};
};
static void QVector_PUSH(benchmark::State& state) {
    QVector< TestStruct> vector;
    for (auto _ : state){

        vector.push_back(TestStruct{});
    }
}
BENCHMARK(QVector_PUSH); //Used to register test function


static void STDVector_PUSH(benchmark::State& state) {
    std::vector< TestStruct> vector;
    for (auto _ : state){
        vector.push_back(TestStruct{});
    }
}
BENCHMARK(STDVector_PUSH); //Used to register test function

// Register the function as a benchmark

BENCHMARK_MAIN(); //Program entry