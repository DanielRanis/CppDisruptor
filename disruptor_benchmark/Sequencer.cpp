// Sequencer.cpp

#include "Sequencer.h"

Sequencer::Sequencer() : cursor_(-1) {
}

long Sequencer::next() const {
    return cursor_.load() + 1;
}

void Sequencer::publish(long sequence) {
    cursor_.store(sequence);
}

long Sequencer::cursor() const {
    return cursor_.load();
}
