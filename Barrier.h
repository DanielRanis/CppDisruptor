// Barrier.h

#ifndef BARRIER_H
#define BARRIER_H

#include <memory>
#include <atomic>
#include "Sequencer.h"
#include "WaitStrategy.h"

class Barrier {
public:
    Barrier(std::shared_ptr<Sequencer> sequencer, WaitStrategy &waitStrategy);

    [[nodiscard]] bool waitFor(long sequence) const;

    void stop();

private:
    std::atomic<bool> running_;
    std::shared_ptr<Sequencer> sequencer_;
    WaitStrategy &waitStrategy_;
};

#endif // BARRIER_H
