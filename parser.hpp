#ifndef "parser_hpp"
#define "parser_hpp"

#include "ast.hpp"
#include "lexer.hpp"
#include <vector>
#include <map>


struct parser {

	int index;
	parser(std::vector<Token *> token) : line(token), index(0) {}
	Token* match(Token k){
		if(lookahead() == k)
			return consume();
		else
			std::cout << "Error expected a token" << std::endl;
	}
	Token* match_if(Token k){
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

	parser(std::vector<Token*>);

	expr* express(){
		return add_express();
	}

	expr* add_express(){
		expr* e1 = mul_express();
	while(true){
		if(match_if(Plus_Tok)){
			expr* e2 = mul_express();
			e1 = new Add_expr(e1,e2);
		}
		else if(match_if(Minus_Tok)){
			expr* e2 = mul_express();
			e1 = new Sub_expr(e1,e2);
		}
		else
			break;
	}	
	return e1;
	}

	expr* mul_express(){
		expr* e1 = una_express();
	while(true){
		if(match_if(Star_Tok)){
			expr* e2 = una_express();
			e1 = new Mul_expr(e1,e2);
		}
		else if(match_if(Slash_Tok)){
			expr* e2 = una_express();
			e1 = new Div_expr(e1,e2);
		}
		else if(match_if(Percent_Tok)){
			expr* e2 = una_express();
			e1 = new Mod_expr(e1,e2);
		}
		else
			break;
	}	
	return e1;
	}

	expr* una_express(){
		if(match_if(Minus_Tok)){
			expr* e = una_express();
			e = new Neg_expr(e);
			return e;	
		}
		else if(match_if(Bang_Tok)){
			expr* e = una_express();
			e = new Not_expr(e);
			return e;
		}
		else
			return prim_express();
	}

	expr* prim_express(){
		switch(lookahead()) {
		case Int_Tok:
			return new Int_expr(consume()->value);
		case LPara_Tok:
		{
			consume();
			expr* e = express();
			match(RPara_Tok);
			return e;
		}
		case Bool_tok:
			return new Bool_expr(consume()->value);
		default:
			break;
		}
	}

	expr* equal_express(){
		expr* e1 = and_express();
	while(true){
		if(match_if(Eql_Tok)){
			expr* e2 = and_express();
			e1 = new Eql_expr(e1,e2);
		}
		else if(match_if(Neq_Tok)){
			expr* e2 = and_express();
			e1 = new Neq_expr(e1,e2);
		}
		else
			break;
	}	
	return e1;
	}	

	expr* and_express(){
		expr* e1 = or_express();
	while(true){
		if(match_if(And_Tok)){
			expr* e2 = or_express();
			e1 = new Ae_expr(e1,e2);
		}
		else
			break;
	}	
	return e1;
	}

	expr* or_express(){
		expr* e1 = order_express();
	while(true){
		if(match_if(Oe_Tok)){
			expr* e2 = order_express();
			e1 = new Oe_expr(e1,e2);
		}
		else
			break;
	}	
	return e1;
	}

	expr* order_express(){
	expr* e1 = cond_express();
	while(true){
		if(match_if(Lss_Tok)){
			expr* e2 = cond_express();
			e1 = new Lss_expr(e1,e2);
		}
		else if(match_if(Gtr_Tok)){
			expr* e2 = cond_express();
			e1 = new Gtr_expr(e1,e2);
		}
		else if(match_if(Gte_Tok)){
			expr* e2 = cond_express();
			e1 = new Gte_expr(e1,e2);
		}
		else if(match_if(Lse_Tok)){
			expr* e2 = cond_express();
			e1 = new Lse_expr(e1,e2);
		}
		else 
			break;
	}
		return e1;
	}

	expr* cond_express(){
		expr* e1 = una_express();
		while(true){
			if(match_if(Cond_Tok){
				expr* e2 = una_expr();
				if(match_if(Oth_Tok)){
					expr* e3 = una_express();
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
