#ifndef stmt_hpp
#define stmt_hpp

#include "ast.hpp"

struct state {
	virtual ~state() { };
};

struct expr_state : state {
	expr_state(Expr* e) : e(e) { }
	Expr* e;
};

struct decl_state : state {
	decl_state(Decl* d) : entity(d) { }
	Decl* entity;
};

struct if_state : state {
	if_state(Expr* e, state* s1, state* s2) : condition(e), s1(s1), s2(s2) { }
	
	Expr* condition;
	state* s1;
	state* s2;
	
}

#endif