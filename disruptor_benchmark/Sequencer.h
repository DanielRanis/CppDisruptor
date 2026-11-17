// Sequencer.h

#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <atomic>

class Sequencer {
public:
    Sequencer();

    long next() const;

    void publish(long sequence);

    [[nodiscard]] long cursor() const;

private:
    std::atomic<long> cursor_;
};

#endif // SEQUENCER_H
