
#include "ast.hpp"

#include <iostream>

Type* check(Context& cxt, Expr* e)
{
  struct V : Expr::Visitor {
    Context& cxt;
    Type* r;
    V(Context& c) : cxt(c) { }

    void visit(Bool_expr* e) {
      r = &cxt.bool_type;
    }
    void visit(And_expr* e) {
      if(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type)
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Or_expr* e) {
      if(check(cxt, e->e1) == &cxt.bool_type && check(cxt, e->e2) == &cxt.bool_type)
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Not_expr* e) {

      if(check(cxt,e->e1) == &cxt.bool_type)
      r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Gtr_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type)
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Lss_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type)
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Grq_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type)
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Leq_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt, e->e2) == &cxt.int_type)
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Eql_expr* e) {
      if(check(cxt, e->e1) == check(cxt, e->e2) )
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Neq_expr* e) {
      if(check(cxt, e->e1) == check(cxt, e->e2) )
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Int_expr* e) {
      r = &cxt.int_type;
	
    }
    void visit(Add_expr* e) {
      if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type)
         r = &cxt.int_type;
	else
		std::cout << "Type error" << std::endl;

    }
    void visit(Sub_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type)
         r = &cxt.int_type;
	else
		std::cout << "Type error" << std::endl;

    }
    void visit(Mul_expr* e) {
  if(check(cxt, e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type)
     r = &cxt.int_type;
	else
		std::cout << "Type error" << std::endl;

    }
    void visit(Div_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type)
         r = &cxt.int_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Mod_expr* e) {
      if(check(cxt, e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type)
         r = &cxt.int_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Neg_expr* e) {
      if(check(cxt,e->e1) == &cxt.int_type)
      r = &cxt.int_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Ae_expr* e) {
      if(check(cxt, e->e1) == check(cxt, e->e2) )
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Oe_expr* e) {
      if(check(cxt, e->e1) == check(cxt, e->e2) )
         r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
    }
    void visit(Cond_expr* e) {
      if(check(cxt, e->e1) == check(cxt, e->e2) && check(cxt, e->e2) == check(cxt, e->e3) )
	r = &cxt.bool_type;
	else
		std::cout << "Type error" << std::endl;
	}
  };
  V vis(cxt);
  e->accept(vis);
  return vis.r;
}
