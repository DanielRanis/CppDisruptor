cmake_minimum_required(VERSION 3.16)

project(CppDisruptor LANGUAGES CXX)

find_package(Threads REQUIRED)

add_executable(disruptor
        Barrier.cpp
        Disruptor.cpp
        Event.cpp
        EventProcessor.cpp
        Producer.cpp
        RingBuffer.cpp
        Sequencer.cpp
        YieldWaitStrategy.cpp
        main.cpp
)

target_compile_features(disruptor PRIVATE cxx_std_17)
target_compile_options(disruptor PRIVATE -Wall)
target_link_libraries(disruptor PRIVATE Threads::Threads)

option(BUILD_DISRUPTOR_BENCHMARK "Build the Google Benchmark executable" OFF)

if (BUILD_DISRUPTOR_BENCHMARK)
    find_package(benchmark CONFIG REQUIRED)

    add_executable(Benchmark
            disruptor_benchmark/Barrier.cpp
            disruptor_benchmark/Benchmark.cpp
            disruptor_benchmark/Disruptor.cpp
            disruptor_benchmark/Event.cpp
            disruptor_benchmark/EventProcessor.cpp
            disruptor_benchmark/Producer.cpp
            disruptor_benchmark/RingBuffer.cpp
            disruptor_benchmark/Sequencer.cpp
            disruptor_benchmark/YieldWaitStrategy.cpp
    )

    target_compile_features(Benchmark PRIVATE cxx_std_20)
    target_compile_options(Benchmark PRIVATE -Wall)
    target_link_libraries(Benchmark PRIVATE benchmark::benchmark Threads::Threads)
endif ()
