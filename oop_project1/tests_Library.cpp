#include "catch2.hpp"
#include "Library.hpp"

TEST_CASE( "Add books to library", "[Library]" )
{
    Book test("1Pesho", "kniga", "file.txt", "Pyrvata kniga na Pesho", 7, "3849938");
    Book sec("2Ivan", "Ivan", "file2.txt", "Pyrvata kniga na Ivan", 0, "38499s38");
    Book three("3ne", "ne", "file2.txt", "Pyrvata kniga na ne", 100, "38499se38");

    Library lib("test_file.txt");
    lib.save(test);
    lib.save(sec);
    lib.save(three);

    // SECTION("sort")
    // {
        // lib.sort(rating, false);
        // lib.sort(author, false);
        // lib.sort(title, true);
        // REQUIRE()
    // }
    SECTION("search")
    {
        lib.search(author, "2Ivan");
        // lib.sort(author, false);
        // lib.sort(title, true);
        // REQUIRE()
    }
}