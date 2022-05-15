program: Book.o Controller.o Library.o main.o
	g++ Book.o Controller.o Library.o main.o -o program

Book.o: Book.cpp
	g++ -c Book.cpp

Controller.o: Controller.cpp
	g++ -c Controller.cpp

Library.o: Library.cpp
	g++ -c Library.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o