#pragma once
#include "SimplePair.hpp"

class TagPair : public SimplePair
{
    TagPair(char* key, char* value);
    TagPair(TagPair &other) = delete;

    // ~TagPair();

};