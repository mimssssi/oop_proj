/*

    The indices are the time (in minutes) past trade opening time, which was 9:30am local time.
    The values are the price (in US dollars) of one share of Apple stock at that time.

Write an efficient function that takes stockPrices and returns the best profit I could have made 
from one purchase and one sale of one share of Apple stock yesterday.

No "shorting"—you need to buy before you can sell. Also, you can't buy and sell in the same time 
step—at least 1 minute has to pass.
*/


#include <iostream>
#include <vector>

int getMaxProfit(std::vector<int> stockPrices)
{
    int minFound = stockPrices.at(0); //keeps the smallest element so far
    // най-голямата разлика в масива до момента
    int maxProfit;
    try
    {
        maxProfit = stockPrices.at(1) - minFound;
    }
    catch(const std::exception& e)
    {
        std::cerr << "There should be at least two prices." << '\n';
    }
    
    for(size_t i = 1; i < stockPrices.size(); ++i)
    {
        if((stockPrices.at(i) - minFound) > maxProfit)
        {
            maxProfit = (stockPrices.at(i) - minFound);
        }
        if(stockPrices.at(i) < minFound)
        {
            minFound = stockPrices.at(i);
        }
    }
    
    return maxProfit;
}

int main()  
{
    // std::vector<int> stockPrices{10, 8, 5, 1};
    std::vector<int> stockPrices{10, 7, 5, 8, 11, 9};

    std::cout<<getMaxProfit(stockPrices);
    return 0;
}