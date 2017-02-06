#include "ast.hpp"

int height(Expr* e)
{
   struct V : Expr::Visitor{
	int r;
	void visit(Bool_expr* e) { r = 0; }
	void visit(And_expr* e) { r = 1 + height(e->e1) + height(e->e2); }
	void visit(Or_expr* e) { r = 1 + height(e->e1) + height(e->e2); }
	void visit(Not_expr* e) { r = 1 + height(e->e1); }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}
