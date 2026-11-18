// EventProcessor.h

#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include "Sequencer.h"
#include "RingBuffer.h"
#include "Barrier.h"
#include <atomic>

class EventProcessor {
public:
    EventProcessor(std::shared_ptr<RingBuffer> ringBuffer, std::shared_ptr<Sequencer> sequencer,
                   std::shared_ptr<Barrier> barrier);

    void run();

    void stop();

private:
    std::shared_ptr<RingBuffer> ringBuffer_;
    std::shared_ptr<Sequencer> sequencer_;
    long nextSequence_;
    std::atomic<bool> running_;
    std::shared_ptr<Barrier> barrier_;
};

#endif // EVENT_PROCESSOR_H
