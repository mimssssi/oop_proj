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
            int index = search();
            if(index != -1)
            {
                lib.printBookInfo(index, true);
            }
            else
            {
                std::cout<<"There is no book which matches your search in our database.";
            }
            break;
        case 3:
            if(authorised())
            {
                addBook();
            }
            break;
        case 4:
            if(authorised())
            {
                removeBook();
            }
            break;
        case 5:
            /* code */
            break;
        
        default:
            break;
        }
        std::cout<<"Type 6 to exit and anything else to continue.";
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

bool Controller::authorised()
{
    std::string input;
    std::cout<<"Password: ";
    std::cin>>input;
    return input == passwd;
}

int Controller::search()
{
    std::cout<<"What would you like to search by:\n1 - Author;\n2 - Title;\n3 - ISBN;\n4 - Description.\n";
    unsigned crit = userInput();
    std::string key;
    std::cin>>key;
    int index = -1;
    switch (crit)
    {
    case 1:
        index = lib.search(author, key);
        break;
    case 2:
        index = lib.search(title, key);
        break;
    case 3:
        index = lib.search(ISBN, key);
        break;
    case 4:
        // index = lib.search(description, key);
        break;
    
    default:
        break;
    }
    return index;
}

void Controller::removeBook()
{
    int index = search();
    if(index != -1)
    {
        std::cout<<"Would you like to delete the file, containing this book:\n1 - Yes;\n2 - No.\n";
        unsigned del = userInput();
        switch (del)
        {
        case 1:
            lib.removeBook(index, true);
            break;
        
        default:
            lib.removeBook(index, false);
            break;
        }
    }
    else
    {
        std::cout<<"There is no book which matches your search in our database.";
    }
}


