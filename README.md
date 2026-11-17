# CppDisruptor

C++ Implementation of the LMAX Disruptor Pattern

## Build

Configure and build the normal executable in Debug or Release mode:

```sh
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug

cmake -S . -B build/release -DCMAKE_BUILD_TYPE=Release
cmake --build build/release
```

The optional Google Benchmark executable uses the sources in `disruptor_benchmark/`. Install Google Benchmark with its
CMake package configuration, then enable it with `BUILD_DISRUPTOR_BENCHMARK` for either build type:

```sh
cmake -S . -B build/debug-benchmark -DCMAKE_BUILD_TYPE=Debug -DBUILD_DISRUPTOR_BENCHMARK=ON
cmake --build build/debug-benchmark

cmake -S . -B build/release-benchmark -DCMAKE_BUILD_TYPE=Release -DBUILD_DISRUPTOR_BENCHMARK=ON
cmake --build build/release-benchmark
```

Each benchmark configuration builds both `disruptor` and `Benchmark`.
