// Disruptor.cpp

#include "Disruptor.h"
#include <thread>
#include <utility>

Disruptor::Disruptor(size_t bufferSize, std::unique_ptr<WaitStrategy> waitStrategy)
    : buffer_(std::make_shared<RingBuffer>(bufferSize)), sequencer_(std::make_shared<Sequencer>()),
      producer_(buffer_, sequencer_), processor_(buffer_, sequencer_), waitStrategy_(std::move(waitStrategy)) {
}

Disruptor::~Disruptor() {
    stop();
}

void Disruptor::start() {
    processorThread_ = std::thread([this]() { processor_.run(); });
}

void Disruptor::onData(const std::string &data) const {
    producer_.onData(data);
}

void Disruptor::stop() {
    processor_.stop();
    if (processorThread_.joinable()) {
        processorThread_.join();
    }
}
