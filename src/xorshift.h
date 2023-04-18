// Created on 4/18/23.

#include <chrono>

class Xorshift128Plus {
public:
    // Constructor using current time as seed
    Xorshift128Plus()
            : state_{0, 0}
    {
        auto now = std::chrono::high_resolution_clock::now();
        uint64_t seed1 = now.time_since_epoch().count();
        uint64_t seed2 = seed1 >> 32;
        state_[0] = seed1;
        state_[1] = seed2;
    }

    // Generate a random integer number within a given range
    uint64_t random_integer(uint64_t min, uint64_t max) {
        return min + next() % (max - min + 1);
    }

private:
    // The state of the generator
    uint64_t state_[2];

    // Generate the next random number in the sequence
    uint64_t next() {
        uint64_t s1 = state_[0];
        const uint64_t s0 = state_[1];
        state_[0] = s0;
        s1 ^= s1 << 23; // a
        state_[1] = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5); // b, c
        return state_[1] + s0;
    }
};