#include "lexer.hpp"
#include "token.hpp"
#include "ast.hpp"
#include "parser.hpp"
#include "eval.hpp"
#include "scope.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <deque>

int main() {
	std::cout << "working" << std::endl;
	std::vector<Token*> vec;
	keyword_table* keywords = new keyword_table();
	symbol_table* symbols = new symbol_table();
	std::deque<scope*> scopes;
	scopes.push_back(new scope());
	std::deque<scope*> stack;
	char line[69];
	while(std::cin.getline(line, 69)){
		std::cout << line << std::endl;

    		lexer lex = lexer(line, keywords, symbols);
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

				parser p(vec, symbols, &stack);
				Expr* express = p.parse();
				if(express != nullptr)
						std::cout << "Eval:" << eval(express) << std::endl;
				else
						std::cout << "error cannot be evaluated" << std:: endl;

		std::cout << std::endl;

	}
}
