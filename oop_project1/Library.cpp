#include "Library.hpp"

Library::Library(std::string file_path)
	: file(file_path, std::ios_base::ate | std::ios::in | std::ios::out)
{
	if (!file.is_open())
	{
		throw std::logic_error("File problem occured");
	}
}

Library::~Library()
{
	if (file.is_open())
	{
		file.close();
	}
}

void Library::save(Book book)
{
    
}