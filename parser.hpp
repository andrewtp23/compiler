#ifndef parser_hpp
#define parser_hpp

#include "ast.hpp"
#include "lexer.hpp"
#include <vector>
#include <map>


struct parser {

	int index;
	parser(std::vector<Token *> token) : line(token), index(0) {}
	Expr* parse(){
		return express();
	}
	std::vector<Token *> line;

	Token* match(Token_name k){
		if(lookahead() == k)
			return consume();
		else
			std::cout << "Error expected a token" << std::endl;
	}
	Token* match_if(Token_name k){
		if(lookahead() == k)
			return consume();
		else
			return nullptr;
	}

	Token* consume(){
		if(eof())
			return nullptr;
		++index;
		return line[index -1];
	}

	int lookahead(){
		if(eof())
			return 0;
		else
			return line[index]->name;
	}

	bool eof() const{
		return index == line.size();
	}

	Expr* express(){
		return cond_express();
	}

	Expr* add_express(){
		Expr* e1 = mul_express();
	while(true){
		if(match_if(Plus_Tok)){
			Expr* e2 = mul_express();
			e1 = new Add_expr(e1,e2);
		}
		else if(match_if(Minus_Tok)){
			Expr* e2 = mul_express();
			e1 = new Sub_expr(e1,e2);
		}
		else
			break;
	}
	return e1;
	}

	Expr* mul_express(){
		Expr* e1 = una_express();
	while(true){
		if(match_if(Star_Tok)){
			Expr* e2 = una_express();
			e1 = new Mul_expr(e1,e2);
		}
		else if(match_if(Slash_Tok)){
			Expr* e2 = una_express();
			e1 = new Div_expr(e1,e2);
		}
		else if(match_if(Percent_Tok)){
			Expr* e2 = una_express();
			e1 = new Mod_expr(e1,e2);
		}
		else
			break;
	}
	return e1;
	}

	Expr* una_express(){
		if(match_if(Minus_Tok)){
			Expr* e = una_express();
			e = new Neg_expr(e);
			return e;
		}
		else if(match_if(Bang_Tok)){
			Expr* e = una_express();
			e = new Not_expr(e);
			return e;
		}
		else
			return prim_express();
	}

	Expr* prim_express(){
		switch(lookahead()) {
		case Int_Tok:
			return new Int_expr(std::stoi(consume()->value));
		case LPara_Tok:
		{
			consume();
			Expr* e = express();
			match(RPara_Tok);
			return e;
		}
		case Bool_Tok:{
			if(consume()->value == "true")
				return new Bool_expr(1);
			else
				return new Bool_expr(0);
		}
		default:
			break;
		}
	}

	Expr* equal_express(){
		Expr* e1 = order_express();
	while(true){
		if(match_if(Eql_Tok)){
			Expr* e2 = order_express();
			e1 = new Eql_expr(e1,e2);
		}
		else if(match_if(Neq_Tok)){
			Expr* e2 = order_express();
			e1 = new Neq_expr(e1,e2);
		}
		else
			break;
	}
	return e1;
	}

	Expr* and_express(){
		Expr* e1 = equal_express();
	while(true){
		if(match_if(And_Tok)){
			Expr* e2 = equal_express();
			e1 = new Ae_expr(e1,e2);
		}
		else
			break;
	}
	return e1;
	}

	Expr* or_express(){
		Expr* e1 = and_express();
	while(true){
		if(match_if(Or_Tok)){
			Expr* e2 = and_express();
			e1 = new Oe_expr(e1,e2);
		}
		else
			break;
	}
	return e1;
	}

	Expr* order_express(){
	Expr* e1 = add_express();
	while(true){
		if(match_if(Lss_Tok)){
			Expr* e2 = add_express();
			e1 = new Lss_expr(e1,e2);
		}
		else if(match_if(Gtr_Tok)){
			Expr* e2 = add_express();
			e1 = new Gtr_expr(e1,e2);
		}
		else if(match_if(Gte_Tok)){
			Expr* e2 = add_express();
			e1 = new Grq_expr(e1,e2);
		}
		else if(match_if(Lse_Tok)){
			Expr* e2 = add_express();
			e1 = new Leq_expr(e1,e2);
		}
		else
			break;
	}
		return e1;
	}

	Expr* cond_express(){
		Expr* e1 = order_express();
		while(true){
			if(match_if(Cond_Tok)){
				Expr* e2 = order_express();
				if(match_if(Oth_Tok)){
					Expr* e3 = order_express();
					e1 = new Cond_expr(e1,e2,e3);
				}
			}
			else
				break;
		}
		return e1;
	}
};

#endif
