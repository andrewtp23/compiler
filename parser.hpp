#ifndef parser_hpp
#define parser_hpp

#include "ast.hpp"
#include "lexer.hpp"
//#include "eval.hpp"
#include "symbols.hpp"
#include "scope.hpp"
#include <vector>
#include <deque>
#include <unordered_map>
#include <iostream>

struct parser {

	int index;
	std::vector<Token *> line;
	std::deque<scope*> &scope_stack;
	std::unordered_map<int, std:;string> names;
	Expr* stmt_seq();
	parser(std::vector<Token *> token, symbol_table* S, std::deque<scope*> &scopes) : line(token), symbols(S), scope_stack(scopes), index(0) {}
	Expr* parse(){
		return stmt_seq();
	}

	bool eof() const{
		return index == line.size();
	}

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

	Expr* stmt_seq(){
		return stmt();
	}

	Expr* stmt(){
		switch(look_ahead()){
			case LBrack_Tok:
				return startblock();

			case RBrack_Tok:
				return endblock();

			case if_kw:
				return Cond_stmt();

			case assert_kw:
				return assertion();

			case var_kw:
				return decl_stmt()->entity->init;

			case Id_Tok:
				if(line.size() > 1)
					if(lin[index + 1]->name == Assign_Tok)
						return assignment();

			default:
				return express_stmt()->expression;
		}
	}

	Decl_stmt* declare_stmt(){
		Decl* d = declaration();
		return new Decl_stmt(d);
	}

	Expr_stmt* express_stmt(){
		Expr* e = express();
		return new Expr_stmt(e);
	}

	Expr* Cond_stmt(){
		consume();
		match_if(LPara_Tok);
		Expr* e1 = express();
		match_if(RPara_Tok);
		Expr* e2 = stmt();
		match_if(else_kw);
		Expr* e3 = stmt();

		return new Cond_expr(e1, e2, e3);
	}

	Expr* startblock(){
		match_if(LBrack_Tok);
		scope.push_back(new scope());
		return nullptr;
	}

	Expr* endblock(){
		match_if(RBrack_Tok);
		scope.pop_back();
		return nullptr;
	}

	Expr* assignment(){
		symbol *x = identifier();
		x = symbols->find(*x);
		match(Assign_Tok);

		for(int i = scope_stack.size() -1; i >= 0; i--){
			if(scope_stack[i]->find(*x) != nullptr){
				Decl* v = new Decl();
				Expr* e = express();
				v->init = e;
				scope_stack[i]->modify(*x, v);
				return e;
			}
		}
	}

	Expr* assertion(){
		consume();
		match_if(LPara_Tok);
		Expr* e = express();
		match_if(RPara_Tok);
		assert(eval(e));
		return nullptr;
	}

	Decl* declar(){
		switch(look_ahead())
		{
			case var_kw:
				return variable_decl();

			default:
				break;
		}
	}

	Decl* variable_decl()
		{
			match_if(var_kw);
			Type* t = type_specifier();
			symbol* x = identifier();
			symbols->insert(*x);
			Decl *v = new Decl();
			match(Assign_Tok);
			Expr* e = express();
			v->init = e;
			scope_stack.back()->insert(*x, v);
			return v;
		}

	Type* type_specifier(){
		switch(lookahead())
		{
			case bool_kw:
				consume();
				return new Bool_type;

			case int_kw:
				consume();
				return new Int_type;

			default:
				std::cout << "type error" << std::endl;
		}
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
			std::cout << "here\n";
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
			std::cout << "invalid token\n";
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

	Expr* ID_express(){
		symbol *x = identifier();
		x = symbols->find(*x);

		for(int i = scope_stack.size() - 1; i >= 0; i--){
			Decl* d = scope_stack[i]->find(*x);
			if(d != nullptr)
				return d->init;
		}
	}

	symbol* identifier(){
		Token* id(Id_Tok);
		symbol* s = &id->value;
		return s;
	}
};

#endif
