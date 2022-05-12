#include "Book.hpp"

Book::Book(std::string author, std::string title, std::string path, std::string description, 
    unsigned rating, std::string ISBN) : 
    author(author), title(title), path(path), description(description), rating(rating), ISBN(ISBN)
   {}