#pragma once
#include "SimplePair.hpp"

class InterpolationPair : public SimplePair
{
    InterpolationPair(char* key, char* value);
    InterpolationPair(InterpolationPair &other) = delete;

    // ~InterpolationPair();
};