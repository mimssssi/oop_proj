#include "Library.hpp"

Library::Library(std::string file_path) : filePath(file_path)
{
	// if (!file.is_open())
	// {
	// 	throw std::logic_error("File problem occured");
	// }
}

void Library::save(Book book)
{
    lib.push_back(book);

}

void Library::writeToFile()
{
	std::fstream file(filePath, std::ios::out);
	// if
	// file<< ;
	// file.close();
}