
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

    }
    /*void visit(Or_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == cxt.bool_type && e->e2.r == cxt.bool_type)
         r = &cxt.bool_type;

    }
    void visit(Not_expr* e) { 
      visit(e->e1);
      if(e->e1.r == cxt.bool_type)
      r = &cxt.bool_type;

    }
    void visit(Add_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == cxt.int_type && e->e2.r == cxt.int_type)
         r = &cxt.int_type;

    }
    void visit(Sub_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == cxt.int_type && e->e2.r == cxt.int_type)
         r = &cxt.int_type;

    }
    void visit(Mul_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == cxt.int_type && e->e2.r == cxt.int_type)
         r = &cxt.int_type;

    }
    void visit(Div_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == cxt.int_type && e->e2.r == cxt.int_type)
         r = &cxt.int_type;

    }
    void visit(Mod_expr* e) { 
    	visit(e->e1);
	visit(e->e2);
      if(e->e1.r == cxt.int_type && e->e2.r == cxt.int_type)
         r = &cxt.int_type;

    }*/
  };
  V vis(cxt);
  e->accept(vis);
  return vis.r;
}

