#ifndef LAB1_RANDOMIZER_H
#define LAB1_RANDOMIZER_H

#include <random>
class Randomizer {
private:
    std::mt19937 rng;
public:
    Randomizer() {
        std::random_device dev;
        this->rng = std::mt19937(dev());
    }

    int operator()(int start = 0, int end = INT16_MAX) {
        size_t delta = 0;
        if (start < 0) {
            delta = -start;
            start = 0;
            end += delta;
        }
        std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);

        return dist(this->rng) - delta;
    }
};

#endif //LAB1_RANDOMIZER_H
