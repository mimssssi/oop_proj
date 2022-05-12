#include "Library.hpp"

Library::Library(std::string file_path)
	: file(file_path, std::ios_base::ate | std::ios::in | std::ios::out)
{
	if (!file.is_open())
	{
		throw std::logic_error("File problem occured");
	}

	// file_size = file.tellg();
	// file.seekg(0, std::ios_base::beg);
}

void Library::save(Book book)
{
    
}