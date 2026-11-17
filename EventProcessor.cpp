// EventProcessor.cpp

#include "EventProcessor.h"
#include <iostream>
#include <utility>

EventProcessor::EventProcessor(std::shared_ptr<RingBuffer> ringBuffer, std::shared_ptr<Sequencer> sequencer)
    : ringBuffer_(std::move(ringBuffer)), sequencer_(std::move(sequencer)), nextSequence_(0), running_(true) {
    std::cout << "EventProcessor Sequencer Addr: " << sequencer_.get() << std::endl;
}

void EventProcessor::run() {
    std::cout << "Consumer running. Waiting for events...\n";
    while (running_.load()) {
        //std::cout << "Consumer is in the while loop. Next sequence to read: " << nextSequence_ << "\n";
        while (nextSequence_ <= sequencer_->cursor()) {
            Event &event = ringBuffer_->get(nextSequence_);
            // std::cout << "[Consumer] Consumed: " << event.get() << " from sequence: " << nextSequence_ << "\n";
            ++nextSequence_;
        }
    }
}

void EventProcessor::stop() {
    running_.store(false);
}
