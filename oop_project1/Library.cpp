#include "Library.hpp"


Library::Library(std::string file_path) : filePath(file_path)
{}

void Library::save(Book book)
{
    lib.push_back(book);
	writeToFile();
}

void Library::writeToFile()
{
	std::fstream file(filePath, std::ios::out);
	if(!file.is_open())
	{
		throw std::logic_error("File problem occured");
	}
	
	for(size_t i = 0; i < lib.size(); ++i)
	{
		file<<"\""<<lib.at(i).title<<"\" by "<<lib.at(i).author<<".\nISBN: "<<lib.at(i).ISBN
		<<"; Rating: "<<lib.at(i).rating<<"; Filepath: "<<lib.at(i).path
		<<";\nDescription: "<<lib.at(i).description<<"\n\n";
	}
	file.close();
}

void Library::sort(sortingCrit by, bool ascending)
{
	///sorts the vector in ascending order by author
	std::sort(lib.begin(), lib.end(), [](Book a, Book b) {
        return a.author[0] < b.author[0];
    });

	printVector(ascending);
}

void Library::printVector(bool ascending)
{
	if(ascending)
	{
		for(size_t i = 0; i < lib.size(); ++i)
		{
			std::cout<<"\""<<lib.at(i).title<<"\" "<<lib.at(i).author<<" "
			<<lib.at(i).ISBN<<"\n";
		}
	}
	else
	{
		for(size_t i =  lib.size(); i > 0; --i)
		{
			std::cout<<"\""<<lib.at(i-1).title<<"\" "<<lib.at(i-1).author<<" "
			<<lib.at(i-1).ISBN<<"\n";
		}
	}
}