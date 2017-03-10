all : calc main

calc : calc.o 
	g++ -std=c++11 calc.o  -o calc

calc.o : calc.cpp lexer.hpp token.hpp
	g++ -std=c++11 -c calc.cpp
	
main : main.o
	g++ -std=c++11 main.o -o main

main.o : main.cpp ast.hpp eval.hpp weight.hpp height.hpp type.hpp
	g++ -std=c++11 -c main.cpp

test : calc
	./calc

clean :
	rm -f calc calc.o
