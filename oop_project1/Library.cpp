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
	

	switch(by)
	{
	case author:
		std::sort(lib.begin(), lib.end(), [](Book one, Book two) {
        return one.author.at(0) < two.author.at(0);
		});	///sorts the vector in ascending order
		break;
	
	case title:
		std::sort(lib.begin(), lib.end(), [](Book one, Book two) {
        return one.title.at(0) < two.title.at(0);
		});	///sorts the vector in ascending order
		break;

	case rating:
		std::sort(lib.begin(), lib.end(), [](Book one, Book two) {
        return one.rating < two.rating;
		});	///sorts the vector in ascending order
		break;
	
	default:
		break;
	}

	printVector(ascending);
}

void Library::printVector(bool ascending)
{
	if(ascending)
	{
		for(size_t i = 0; i < lib.size(); ++i)
		{
			printBookInfo(i, false);
		}
	}
	else
	{
		for(size_t i =  lib.size(); i > 0; --i)
		{
			printBookInfo(i-1, false);
		}
	}
}

void Library::printBookInfo(size_t pos, bool detailed)
{
	std::cout<<"\""<<lib.at(pos).title<<"\" "<<lib.at(pos).author<<" "
		<<lib.at(pos).ISBN<<"\n";
	if(detailed)
	{
		std::cout<<"Rating: "<<lib.at(pos).rating<<"; Filepath: "<<lib.at(pos).path
		<<";\nDescription: "<<lib.at(pos).description<<"\n\n";
	}
}