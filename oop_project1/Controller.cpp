#include "Controller.hpp"

Controller::Controller()
{}

Controller& Controller::instance()
{
    static Controller menu;
    return menu;
}