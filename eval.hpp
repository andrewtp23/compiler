
#include "ast.hpp"

bool 
eval(Expr* e)
{
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = e->val; }
    void visit(And_expr* e) { r = eval(e->e1) & eval(e->e2); }
    void visit(Or_expr* e) { r = eval(e->e1) | eval(e->e2); }
    void visit(Not_expr* e) { r = !eval(e->e1); }
  };
  V vis;
  e->accept(vis);
  return vis.r;

  // if (Bool_expr* expr = dynamic_cast<Bool_expr*>(e))
  //   return expr->val;
  // if (And_expr* expr = dynamic_cast<And_expr*>(e))
  //   return eval(expr->e1) & eval(expr->e2);
  // if (Or_expr* expr = dynamic_cast<Or_expr*>(e))
  //   return eval(expr->e1) | eval(expr->e2);
  // if (Not_expr* expr = dynamic_cast<Not_expr*>(e))
  //   return !eval(expr->e1);
  // else
  //   assert(false && "unknown expression");
}
