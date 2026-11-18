// Disruptor.cpp

#include "Disruptor.h"
#include <stdexcept>
#include <thread>
#include <utility>

std::unique_ptr<WaitStrategy> Disruptor::requireWaitStrategy(
    std::unique_ptr<WaitStrategy> strategy) {
    if (!strategy) {
        throw std::invalid_argument("Disruptor requires a wait strategy");
    }
    return strategy;
}

Disruptor::Disruptor(size_t bufferSize, std::unique_ptr<WaitStrategy> waitStrategy)
    : waitStrategy_(requireWaitStrategy(std::move(waitStrategy))), buffer_(std::make_shared<RingBuffer>(bufferSize)),
      sequencer_(std::make_shared<Sequencer>()), barrier_(std::make_shared<Barrier>(sequencer_, *waitStrategy_)),
      producer_(buffer_, sequencer_), processor_(buffer_, sequencer_, barrier_) {
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
    barrier_->stop();
    processor_.stop();
    if (processorThread_.joinable()) {
        processorThread_.join();
    }
}
