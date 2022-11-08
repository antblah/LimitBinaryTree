Book.o:			Source.o Order.o BinaryTree.o 
				g++ -std=c++17 -o Book Main.o Order.o BinaryTree.o 


Source.o:		Main.cpp BinaryTree.h
				g++ -c Main.cpp

Order.o:   		Order.cpp Order.h
				g++ -c Order.cpp


BinaryTree.o:	BinaryTree.cpp BinaryTree.h
				g++ -c BinaryTree.cpp