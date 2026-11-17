#include "Disruptor.h"
#include "YieldWaitStrategy.h"
#include <chrono>
#include <memory>
#include <thread>

int main() {
    size_t bufferSize = 1024;

    Disruptor disruptor(bufferSize, std::make_unique<YieldWaitStrategy>());

    disruptor.start();

    for (int i = 0; i < 100; ++i) {
        disruptor.onData("Event " + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // slow down the producer a bit
    }

    disruptor.stop();

    return 0;
}
