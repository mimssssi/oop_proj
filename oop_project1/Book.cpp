#include "Book.hpp"

// unsigned Book::gen = 0;

Book::Book(std::string author, std::string title, std::string path, std::string description, 
    unsigned rating, std::string ISBN) : 
    author(author), title(title), path(path), description(description), rating(rating), ISBN(ISBN)
   {
    //    libID = gen++;
   }

Book::Book()
{}
