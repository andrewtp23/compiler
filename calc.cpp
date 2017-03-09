#include "lexer.hpp"
#include "token.hpp"
#include <vector>
#include <string>
#include <iostream>

int main() {
	std::cout << "working" << std::endl;
	std::vector<Token*> vec;
	char line[69];
	while(std::cin.getline(line, 69)){
		std::cout << line << std::endl;

    		lexer lex = lexer(line);
    		Token *current = lex.next();
    		while (current != nullptr)
    		{
       	 	vec.push_back(current);
       	 	current = lex.next();
    		}

    		for (int i = 0; i < vec.size(); ++i)
    		{
        		std::cout << vec[i]->name << " " << vec[i] << "\n";
    		}
		std::cout << std::endl;

	}
}

