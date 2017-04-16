#include "lexer.hpp"
#include "token.hpp"
#include "ast.hpp"
#include "parser.hpp"
#include "eval.hpp"
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

				parser parse(lex);
				Expr* express = parse.parse();
				if(express != nullptr)
						std::cout << "Eval:" << eval(express) << std::endl;
				else
						std::cout << "error cannot be evaluated" << std:: endl;

		std::cout << std::endl;

	}
}
