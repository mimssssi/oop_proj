#pragma once

#include <fstream>
#include <vector>
#include "Book.hpp"

class Library
{
private:
    std::fstream file;
	std::size_t file_size;
	bool file_open;

    std::vector<Book> lib;

public:

    Library(const Library& other) = delete;
    void operator=(const Library& other) = delete;
   
    Library(std::string file_path);
    
	~Library();

    // void read();    ///reads book info from the database
    void save(Book book);    ///saves book info to the vector and to the file
    
};
