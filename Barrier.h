// Barrier.h

#ifndef BARRIER_H
#define BARRIER_H

#include <memory>
#include "Sequencer.h"
#include "WaitStrategy.h"

class Barrier {
public:
    Barrier(std::shared_ptr<Sequencer> sequencer, WaitStrategy& waitStrategy);

    void waitFor(long sequence) const;

private:
    std::shared_ptr<Sequencer> sequencer_;
    WaitStrategy& waitStrategy_;
};

#endif // BARRIER_H
