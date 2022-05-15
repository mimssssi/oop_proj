#include "Library.hpp"

int main()
{
    Book test("Pesho", "kniga", "file.txt", "Pyrvata kniga na Pesho", 10, "3849938");
    Book sec("Ivan", "Ivan", "file2.txt", "Pyrvata kniga na Ivan", 10, "38499s38");
    Book three("ne", "ne", "file2.txt", "Pyrvata kniga na ne", 10, "38499se38");

    // std::cout<<test.author<<" "<<test.libID<<'\n';
    // std::cout<<sec.author<<" "<<sec.libID<<'\n';
    // std::cout<<three.author<<" "<<three.libID<<'\n';
    return 0;
}