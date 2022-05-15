#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include "Book.hpp"

///Used to denote the desired sorting or search criterion
enum crit{author, title, rating, ISBN};

//< Keeps books in a vector and keeps the database up to date
class Library
{
private:
    std::string filePath;

    std::vector<Book> lib;
    void writeToFile();
    void printVector(bool ascending);
    std::string lower(std::string str);

public:

    Library(const Library& other) = delete;
    void operator=(const Library& other) = delete;
   
    Library(std::string filePath);

    ///returns how many books are currently stored. Used for unit tests
    size_t size();
    ///saves book info to the vector and updates the file
    void save(Book book);    
    ///sorts the vector, containing the books, by the chosen criteria.
    void sort(crit by, bool ascending);
    ///returns the index of the first matching book found, -1 if not found
    int search(crit by, std::string key);
    ///prints book info
    void printBookInfo(size_t pos, bool detailed);

    void removeBook(size_t pos, bool rmFile);
};

// std::sort sorts the array using ... 