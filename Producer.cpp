// Producer.cpp

#include "Producer.h"
#include <iostream>
#include <utility>

Producer::Producer(std::shared_ptr<RingBuffer> ringBuffer, std::shared_ptr<Sequencer> sequencer)
    : ringBuffer_(std::move(ringBuffer)), sequencer_(std::move(sequencer)) {
    std::cout << "Producer Sequencer Addr: " << sequencer_.get() << std::endl;
}

void Producer::onData(const std::string &data) const {
    long sequence = sequencer_->next();
    Event &event = ringBuffer_->get(sequence);
    event.set(data);
    sequencer_->publish(sequence);
    std::cout << "[Producer] Published: " << data << " at sequence: " << sequence << "\n";
}
