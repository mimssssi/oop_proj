#pragma once

#include "Library.hpp"

///Singleton class, used to comunicate with the user.
class Controller
{
private:
    std::string passwd = "Duner";
    Library lib;

    Controller();
    bool authorised();


public:

	Controller(const Controller&) = delete; //при всеки опит функцията да бъде извикана ще даде грешка
	Controller& operator =(const Controller&) = delete;//availiable in c++ 11

    static Controller& instance();
    void run();

    ///user input for the main menu
    unsigned userInput();
    ///interactive
    void sort();
    ///interactive. Returns the index of a book, which matches the search; -1 if not found
    int search();
    ///interactive
    void addBook();
    ///interactive
    void removeBook();

};

