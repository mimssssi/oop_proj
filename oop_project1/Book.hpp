#include <iostream>
#include <string>


class Book
{
    std::string author;
    std::string title;
    std::string path;
    std::string description;
    unsigned rating;
    std::string ISBN;

public:
    Book(std::string author, std::string title, std::string path, std::string description, 
    unsigned rating, std::string ISBN);
};
