
#include "ast.hpp"

#include <iostream>

Type*
check(Context& cxt, Expr* e)
{
  struct V : Expr::Visitor {
    Context& cxt;
    Type* r;
    V(Context& c) : cxt(c) { }
    void visit(Bool_expr* e) { 
      r = &cxt.bool_type;
    }
    void visit(And_expr* e) { 
      // check that e->e1 is bool
      // check that e->e2 is bool
      r = &cxt.bool_type;
    }
    void visit(Or_expr* e) { 
      // check that e->e1 is bool
      // check that e->e2 is bool
      r = &cxt.bool_type;
    }
    void visit(Not_expr* e) { 
      // check that e->e1 is bool
      r = &cxt.bool_type;
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
