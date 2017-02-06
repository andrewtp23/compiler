#include "ast.hpp"

int weight(Expr* e)
{
   struct V : Expr::Visitor{
	int r;
	void visit(Bool_expr* e) { r = 1; }
	void visit(And_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Or_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Not_expr* e) { r = 1 + weight(e->e1); }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}
