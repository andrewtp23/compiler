#include "ast.hpp"

int weight(Expr* e)
{
   struct V : Expr::Visitor{
	int r;
	void visit(Bool_expr* e) { r = 1; }
	void visit(And_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Or_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Not_expr* e) { r = 1 + weight(e->e1); }
  void visit(Gtr_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
  void visit(Lss_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
  void visit(Grq_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
  void visit(Leq_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
  void visit(Eql_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Int_expr* e) { r = 1; }
	void visit(Add_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Sub_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Mul_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Div_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }
	void visit(Mod_expr* e) { r = 1 + weight(e->e1) + weight(e->e2); }

  };
  V vis;
  e->accept(vis);
  return vis.r;
}
