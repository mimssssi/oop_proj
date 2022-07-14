#pragma once
#include <iostream>

class SimplePair
{
    char* key = nullptr;
    char* value = nullptr;

    public:
    SimplePair(char* key, char* value);
    SimplePair(SimplePair &other);

    bool operator ==(SimplePair* other);

    virtual ~SimplePair();
};