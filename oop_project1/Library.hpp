#pragma once

#include <fstream>
#include <vector>
#include "Book.hpp"

//< Keeps books in a vector and keeps the database up to date
class Library
{
private:
    // std::fstream file;
	// std::size_t file_size;
	// bool file_open;
    std::string filePath;

    std::vector<Book> lib;

public:

    Library(const Library& other) = delete;
    void operator=(const Library& other) = delete;
   
    Library(std::string filePath);
    
    // void read();    ///reads book info from the database
    void save(Book book);    ///saves book info to the vector and updates the file
    void writeToFile();
};

//std::sort sorts the array using ...