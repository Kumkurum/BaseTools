cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 20)

project(BaseTools)
file(GLOB SOURCE src/* include/${PROJECT_NAME}/*)
add_library(${PROJECT_NAME} ${SOURCE})
add_library(BaseTools::tools ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(submodule)
if (${TEST})
    find_package(GTest)
    file(GLOB SOURCE_TEST test/* src/* include/${PROJECT_NAME}/*)
    add_executable(Test_${PROJECT_NAME}  ${SOURCE_TEST})
    target_link_libraries(Test_${PROJECT_NAME}
            GTest::GTest
    )
endif ()

if (${BENCHMARK})
    find_package(benchmark)
    find_package(QT NAMES Qt6 Qt5 COMPONENTS Core)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core)
    file(GLOB SOURCE_TEST benchmarks/* src/* include/${PROJECT_NAME}/*)
    add_executable(Bench_${PROJECT_NAME}  ${SOURCE_TEST})
    set(CMAKE_CXX_FLAGS_DEBUG "-O3")
    target_link_libraries(Bench_${PROJECT_NAME}
            benchmark
            pthread
            Qt${QT_VERSION_MAJOR}::Core
    )
endif ()


#execute_process(COMMAND git describe --tags --always WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE GIT_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
#execute_process(COMMAND ${CMAKE_COMMAND} -E env TZ=UTC git log -1 --format=%cd --date=format-local:"%d.%m.%Y %H:%M:%S" WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE GIT_SOURCE_DATE OUTPUT_STRIP_TRAILING_WHITESPACE)
#string(TIMESTAMP PROJECT_BUILD_DATE "%d.%m.%Y %H:%M:%S" UTC)
#add_definitions(-DPROJECT_NAME="${PROJECT_NAME}" -DPROJECT_VERSION="${GIT_VERSION}" -DPROJECT_SOURCE_DATE=${GIT_SOURCE_DATE} -DPROJECT_BUILD_DATE="${PROJECT_BUILD_DATE}")
