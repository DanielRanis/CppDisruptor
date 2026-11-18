// Barrier.cpp

#include "Barrier.h"
#include <thread>
#include <utility>

Barrier::Barrier(std::shared_ptr<Sequencer> sequencer, WaitStrategy &waitStrategy) : running_(true),
    sequencer_(std::move(sequencer)),
    waitStrategy_(waitStrategy) {
}

bool Barrier::waitFor(const long sequence) const {
    while (running_.load() && sequence > sequencer_->cursor()) {
        waitStrategy_.wait();
    }
    return running_.load();
}

void Barrier::stop() {
    running_.store(false);
}
