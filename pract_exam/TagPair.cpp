#include "TagPair.hpp"

TagPair::TagPair(char* key, char* value) : SimplePair(key, value)
{
    if(value[0] != '\"')
    {
        throw std::runtime_error("Invalid value.");
    }
    int len = 0; 
    while(value[len])
    {
        ++len;
    }
    if(value[len-1] != '\"')
    {
        throw std::runtime_error("Invalid value.");
    }

    

}