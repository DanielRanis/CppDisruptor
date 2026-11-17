// Disruptor.h

#ifndef DISRUPTOR_H
#define DISRUPTOR_H

#include <memory>
#include <string>
#include <thread>
#include "EventProcessor.h"
#include "Producer.h"
#include "RingBuffer.h"
#include "Sequencer.h"
#include "WaitStrategy.h"
#include "Barrier.h"

class Disruptor {
public:
    explicit Disruptor(size_t bufferSize, std::unique_ptr<WaitStrategy> waitStrategy);

    ~Disruptor();

    void start();

    void onData(const std::string &data) const;

    void stop();

private:
    std::unique_ptr<WaitStrategy> waitStrategy_;
    std::shared_ptr<RingBuffer> buffer_;
    std::shared_ptr<Sequencer> sequencer_;
    std::shared_ptr<Barrier> barrier_;
    Producer producer_;
    EventProcessor processor_;
    std::thread processorThread_;

    static std::unique_ptr<WaitStrategy> requireWaitStrategy(std::unique_ptr<WaitStrategy> strategy);
};

#endif // DISRUPTOR_H
