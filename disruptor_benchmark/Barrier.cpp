// Barrier.cpp

#include "Barrier.h"
#include <thread>
#include <utility>

Barrier::Barrier(std::shared_ptr<Sequencer> sequencer) : sequencer_(std::move(sequencer)) {
}

void Barrier::waitFor(const long sequence) const {
    while (sequence > sequencer_->cursor()) {
        std::this_thread::yield();
    }
}
