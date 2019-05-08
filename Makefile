HelloWorld: main.o Executive.o Pokemon.o TreeTest.o 
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o TreeTest.o -o HelloWorld
main.o: main.cpp Executive.h Executive.cpp BNode.h BinarySearchTree.h Pokemon.o TreeTest.o
	g++ -std=c++11 -g -Wall -c main.cpp
Executive.o: Executive.h Executive.cpp BNode.h BNode.hpp BinarySearchTree.h BinarySearchTree.hpp Visit.h Visit.hpp
	g++ -std=c++11 -g -Wall -c Executive.cpp
Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp
TreeTest.o: TreeTest.h TreeTest.cpp
	g++ -std=c++11 -g -Wall -c TreeTest.cpp
clean:
	rm *.o HelloWorld
