#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include "Book.hpp"

/// Used to denote the desired sorting or search criterion
enum crit
{
    author,
    title,
    rating,
    ISBN,
    description
};

/// Keeps books in a vector and keeps the database up to date
class Library
{
private:
    ///file, which contains the database
    std::string filePath = "data.txt";

    ///container for quick access the books
    std::vector<Book> lib;

    ///writes book info to the database
    void writeToFile();
    ///prints the the books currently in the database
    void printVector(bool ascending);
    ///used to ensure case-insensitive search
    std::string lower(std::string str);
    ///The code for isSubstring is taken from https://www.geeksforgeeks.org/
    int isSubstring(std::string desc, std::string key);

public:
    Library(const Library &other) = delete;
    void operator=(const Library &other) = delete;

    Library();
    Library(std::string filePath);

    /// returns how many books are currently stored. Used for unit tests
    size_t size();
    /// saves book info to the vector and updates the file
    void save(Book book);
    /// sorts the vector, containing the books, by the chosen criteria.
    void sort(crit by, bool ascending);
    /// returns the index of the first matching book found, -1 if not found
    int search(crit by, std::string key);
    /// prints book info
    void printBookInfo(size_t pos, bool detailed);
    ///@rowsOnPage > 0 - Prints the book page by page; else prints by sentences
    void printBook(size_t pos, unsigned rowsOnPage);
    ///@pos - index of the book to be removed in the vector
    void removeBook(size_t pos, bool rmFile);
};

// std::sort sorts the array 