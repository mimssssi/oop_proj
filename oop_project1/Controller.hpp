#pragma once

#include "Library.hpp"

///Singleton class, used to comunicate with the user.
class Controller
{
private:
    std::string passwd = "Duner";

    Controller();
    
public:

	Controller(const Controller&) = delete; //при всеки опит функцията да бъде извикана ще даде грешка
	Controller& operator =(const Controller&) = delete;//availiable in c++ 11

    static Controller& instance();
    void run();
};

