#include "catch2.hpp"
#include "Controller.hpp"

Book test("1Pesho", "kniga", "file.txt", "Pyrvata kniga na Pesho", 7, "3849938");
Book sec("2Ivan", "Ivan", "file2.txt", "Pyrvata kniga na Ivan", 0, "38499s38");
Book three("3ne", "ne", "file2.txt", "Pyrvata kniga na ne", 100, "38499se38");

TEST_CASE( "Library", "[Library]" )
{
    Library lib("test_file.txt");
    lib.save(test);
    lib.save(sec);
    lib.save(three);

    // lib.sort(rating, false);
    // lib.sort(author, false);
    // lib.sort(title, true);
        
    SECTION("search")
    {
        REQUIRE(lib.search(author, "2Ivan") != -1);
        REQUIRE(lib.search(author, "2Ivan") == lib.search(author, "2iVan"));
    }
    SECTION("print book")
    {
        lib.printBook(0, 2);
    }
    SECTION("remove")
    {
        REQUIRE_THROWS_AS(lib.removeBook(1, true), std::runtime_error);
        lib.removeBook(1, false);
        REQUIRE(lib.size() == 2);
        std::fstream file;
        file.open("file.txt", std::ios::out);
        file.close();
        lib.removeBook(0, true);
    }
}

TEST_CASE( "Controller", "[Controller]" )
{
    Controller& cont = Controller::instance();
    // cont.addBook();

}