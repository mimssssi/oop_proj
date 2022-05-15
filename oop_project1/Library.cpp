#include "Library.hpp"


Library::Library(std::string file_path) : filePath(file_path)
{}

Library::Library()
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

void Library::sort(crit by, bool ascending)
{	
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
		<<";\nDescription: "<<lib.at(pos).description<<"\n";
	}
}

int Library::search(crit by, std::string key)
{
	switch (by)
	{
	case author:
		for(size_t i = 0; i < lib.size(); ++i)
		{
			if(lower(lib.at(i).author) == lower(key))
			{
				return i;
			}
		}
		break;
	case title:
		for(size_t i = 0; i < lib.size(); ++i)
		{
			if(lower(lib.at(i).title) == lower(key))
			{
				return i;
			}
		}
		break;
	case ISBN:
		for(size_t i = 0; i < lib.size(); ++i)
		{
			if(lower(lib.at(i).ISBN) == lower(key))
			{
				// printBookInfo(i, true);
				return i;
			}
		}
		break;
	
	default:
		return -1;
		break;
	}
	return -1;
}

std::string Library::lower(std::string str)
{
	std::string lc;
	for(size_t i = 0; i < str.size(); ++i)
	{
		lc.push_back(tolower(str.c_str()[i])); ///this should not get out of bounds
	}
	return lc;
}

void Library::removeBook(size_t pos, bool rmFile)
{
	if(rmFile)
	{
		int rm = remove(lib.at(pos).path.c_str());
		if(rm)
		{
			throw std::runtime_error ("Unable to delete this file.");
		}
	}

	lib.erase(lib.begin() + pos);
	writeToFile();
}

size_t Library::size()
{
	return lib.size();
}

void Library::printBook(size_t pos, unsigned rowsOnPage)
{
	std::fstream file(lib.at(pos).path, std::ios::in);
	if(!file.is_open())
	{
		throw std::logic_error("The file containing this book cannot be found.");
	}
	std::string curr; 
	if(rowsOnPage)
	{
		std::string cont;
		while (!(file.peek() == std::char_traits<char>::eof()))
		{
			for(size_t i = 0; i < rowsOnPage; ++i)
			{
				if(!(file.peek() == std::char_traits<char>::eof()))
				{
					std::getline(file, curr);
					std::cout<<curr<<std::endl;
					file<<std::endl;
				}
				else
				{
					break;
				}
				std::cout<<"Type 6 to exit book and anything else to continue.";
				std::cin>>cont;
				if(cont == "6")
				{
					break; 
				}
			}
			if(cont == "6")
			{
				break; 
			}
		}
	}
}


