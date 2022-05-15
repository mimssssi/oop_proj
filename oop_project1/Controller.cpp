#include <limits>
#include "Controller.hpp"

Controller::Controller()
{}

Controller& Controller::instance()
{
    static Controller inst;
    return inst;
}

void Controller::run()
{
    unsigned marker = 0;
    while(marker != 6)
    {
        std::cout<<"Please select an option by typing the respective number:\n"<<
            "1 - Sorted List;\n2 - Search;\n3 - Add a Book;\n4 - Remove a Book;\n"<<
            "5 - Print a Book;\n6 - Exit.\n";
        marker = userInput();
    
        switch (marker)
        {
        case 1:
            sort();
            break;
        case 2:
            /* code */
            break;
        case 3:
            addBook();
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        
        default:
            break;
        }
        std::cout<<"Type anything to continue.";
        marker = userInput();
    }
}

unsigned Controller::userInput()
{
    unsigned marker;
    std::cin>>marker;
    if(!std::cin)
    {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        marker = 0;
    }

    return marker;
}

void Controller::sort()
{
    std::cout<<"What would you like to sort by:\n1 - Author;\n2 - Title;\n3 - Rating.\n";
    unsigned crit = userInput();
    std::cout<<"Choose an order:\n1 - Ascending;\n2 - Descending.\n";
    unsigned ord = userInput();
    switch (crit)
    {
    case 1:
        lib.sort(author, ord == 1);
        break;
    case 2:
        lib.sort(title, ord == 1);
        break;
    case 3:
        lib.sort(rating, ord == 1);
        break;
    
    default:
        break;
    }
    
}

void Controller::addBook()
{
    Book temp;
    std::cout<<"Enter Title:\n";
    std::cin>>temp.title;
    std::cout<<"\nEnter Author:\n";
    std::cin>>temp.author;
    std::cout<<"\nEnter ISBN:\n";
    std::cin>>temp.ISBN;
    std::cout<<"\nEnter Rating:\n";
    unsigned rating = userInput();
    temp.rating = rating;
    std::cout<<"\nEnter Description:\n";
    std::cin>>temp.description;
    std::cout<<"\nEnter File Path:\n";
    std::cin>>temp.path;

    lib.save(temp);
}

