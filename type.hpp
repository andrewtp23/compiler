
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
	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == bool_type && e->e2.r == bool_type)
         r = &cxt.bool_type;
      else
	 std::cout << "Error";
    }
    void visit(Or_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == bool_type && e->e2.r == bool_type)
         r = &cxt.bool_type;
      else
	 std::cout << "Error";
    }
    void visit(Not_expr* e) { 
      visit(e->e1);
      if(e->e1.r == bool_type)
      r = &cxt.bool_type;
      else
	std::cout << "Error";
    }
  };
  V vis(cxt);
  e->accept(vis);
  return vis.r;
}


void
print(Expr* e)
{
  struct V : Expr::Visitor {
    void print_enclosed(Expr* e) {
      if (needs_parens(e)) {
        std::cout << '(';
        print(e);
        std::cout << ')';
      }
      else {
        print(e);
      }
    }

    void visit(Bool_expr* e) { 
      if (e->val)
        std::cout << "true";
      else
        std::cout << "false";
    }
    void visit(And_expr* e) { 
      print_enclosed(e->e1);
      std::cout << " & ";
      print_enclosed(e->e2);
    }
    void visit(Or_expr* e) { 
      print_enclosed(e->e1);
      std::cout << " | ";
      print_enclosed(e->e2);
    }
    void visit(Not_expr* e) { 
      std::cout << '!';
      print_enclosed(e->e1);
    }
  };
  V vis;
  e->accept(vis);
}
