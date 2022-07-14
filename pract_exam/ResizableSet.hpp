#pragma once
#include <iostream>

template<typename T> 
class ResizableSet
{
    T* storage = nullptr;
    size_t size = 0;

    public:
    ResizableSet();
    ResizableSet(ResizableSet& other) = delete;
    ResizableSet operator =(ResizableSet& other) = delete;

    ~ResizableSet();

    void addElement(T* el)
    {
        for(size_t i = 0; i < size; ++i)
        {
            if(el == storage[i])
            {
                throw std::runtime_error("This element is already in the Set.");
            }
        }
        T* tempSt = new T[size + 1];
        for(size_t i = 0; i < size; ++i)
        {
            tempSt[i] = storage[i];
        }
        tempSt[size] = el;
        delete[] storage;
        storage = tempSt;
        tempSt = nullptr;
        size += 1;
    }

    bool removeElement(size_t index)
    {
        if(index < size)
        {   
            T* tempSt = new T[size - 1];
            for(size_t i = 0; i < index; ++i)
            {
                tempSt[i] = storage[i];
            }
            for(size_t i = index + 1; i < size; ++i)
            {
                tempSt[i] = storage[i];
            }
            delete[] storage;
            storage = tempSt;
            tempSt = nullptr;
            size -= 1;
        }
        else
        {
            return false;
        }
    }
};

