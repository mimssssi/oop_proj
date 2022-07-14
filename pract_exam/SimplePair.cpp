#include "SimplePair.hpp"

SimplePair::SimplePair(char* key, char* value)
{
    int index = 1;
    if(key[0] >= 'a' && key[0] <= 'z')
    {
        while((key[index] >= 'a' && key[index] <= 'z') || key[index] == '_')
        {
            index += 1;
        }

        if(key[index] != '\0')
        {
            throw std::runtime_error("invalid character");
        }
    }
    else
    {
        throw std::runtime_error("invalid character (0)");
    }

    int len = 0; 
    while(key[len])
    {
        len +=1;
    }
    char* tempKey = new char[len];
    this->key = tempKey;
    for(size_t i = 0; i < len; ++i)
    {
        this->key[i] = key[i];
    }
    tempKey = nullptr;

    len = 0;
    while(value[len])
    {
        len += 1;
    }
    char* tempValue;
    try
    {
        tempValue = new char[len];
    }
    catch(const std::exception& e)
    {
        delete[] this->key;
        std::cerr << e.what() << '\n';
    }
    
    this->value = tempValue;
    for(size_t i = 0; i < len; ++i)
    {
        this->value[i] = value[i];
    }
    tempValue = nullptr;
}

SimplePair::SimplePair(SimplePair &other) : SimplePair(other.key, other.value)
{}

SimplePair::~SimplePair()
{
    delete[] key;
    delete[] value;
}

bool SimplePair::operator ==(SimplePair* other)
{
    //if this-> key == other->key
}