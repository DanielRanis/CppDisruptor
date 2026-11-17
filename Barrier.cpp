// Barrier.cpp

#include "Barrier.h"
#include <thread>
#include <utility>

Barrier::Barrier(std::shared_ptr<Sequencer> sequencer, WaitStrategy& waitStrategy) : sequencer_(std::move(sequencer)), waitStrategy_(waitStrategy) {
}

void Barrier::waitFor(const long sequence) const {
    while (sequence > sequencer_->cursor()) {
        waitStrategy_.wait();
    }
}
