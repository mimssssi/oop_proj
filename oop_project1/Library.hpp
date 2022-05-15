#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include "Book.hpp"

///Used to denote the desired sorting criterion
enum sortingCrit{author, title, rating};

//< Keeps books in a vector and keeps the database up to date
class Library
{
private:
    // std::fstream file;
	// std::size_t file_size;
	// bool file_open;
    std::string filePath;

    std::vector<Book> lib;
    void writeToFile();
    void printVector(bool ascending);

public:

    Library(const Library& other) = delete;
    void operator=(const Library& other) = delete;
   
    Library(std::string filePath);
    
    void save(Book book);    ///saves book info to the vector and updates the file
    //sorts the vector, containing the books, by the chosen criteria.
    void sort(sortingCrit by, bool ascending);
};

//std::sort sorts the array using ...