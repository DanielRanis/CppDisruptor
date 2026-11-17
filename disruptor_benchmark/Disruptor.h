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

class Disruptor {
public:
    explicit Disruptor(size_t bufferSize, std::unique_ptr<WaitStrategy> waitStrategy);

    ~Disruptor();

    void start();

    void onData(const std::string &data) const;

    void stop();

private:
    std::shared_ptr<RingBuffer> buffer_;
    std::shared_ptr<Sequencer> sequencer_;
    Producer producer_;
    EventProcessor processor_;
    std::unique_ptr<WaitStrategy> waitStrategy_;
    std::thread processorThread_;
};

#endif // DISRUPTOR_H
