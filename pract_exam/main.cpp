#include "SimplePair.hpp"

int main()
{

        // std::cout<<"AA";
    char key[] = {"abvg"};
    char val[] = {"djdk"};

    // std::cout<<key[0] > ;
    try
    {
        SimplePair temp(key, val);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    int size = 0;
    while (key[size])
    {
        size += 1;
    }
    // std::cout<<size;
    return 0;
}