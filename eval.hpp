#include "ast.hpp"

int eval(Expr* e)
{
  struct V : Expr::Visitor {
    int r;
    Context cxt;
    void visit(Bool_expr* e) { r = e->getval(); }
    void visit(And_expr* e) { r = eval(e->gete1()) & eval(e->gete2()); }
    void visit(Or_expr* e) { r = eval(e->gete1()) | eval(e->gete2()); }
    void visit(Not_expr* e) { r = !eval(e->gete1()); }
    void visit(Gtr_expr*e) { r = eval(e->gete1()) > eval(e->gete2()); }
    void visit(Lss_expr*e) { r = eval(e->gete1()) < eval(e->gete2()); }
    void visit(Grq_expr*e) { r = eval(e->gete1()) >= eval(e->gete2()); }
    void visit(Leq_expr*e) { r = eval(e->gete1()) <= eval(e->gete2()); }
    void visit(Eql_expr*e) { r = eval(e->gete1()) == eval(e->gete2()); }
    void visit(Neq_expr*e) { r = eval(e->gete1()) != eval(e->gete2()); }
    void visit(Int_expr* e) { r = e->getval(); }
    void visit(Add_expr* e) { r = eval(e->gete1()) + eval(e->gete2()); }
    void visit(Sub_expr* e) { r = eval(e->gete1()) - eval(e->gete2()); }
    void visit(Mul_expr* e) { r = eval(e->gete1()) * eval(e->gete2()); }
    void visit(Div_expr* e) { r = eval(e->gete1()) / eval(e->gete2()); }
    void visit(Mod_expr* e) { r = eval(e->gete1()) % eval(e->gete2()); }
    void visit(Neg_expr* e) { r = 0 - eval(e->gete1()) ; }
    void visit(Ae_expr* e) { r = eval(e->gete1()) && eval(e->gete2()); }
    void visit(Oe_expr* e) { r = eval(e->gete1()) || eval(e->gete2()); }
    void visit(Cond_expr* e) {
	if( eval(e->gete1()) == true)
		r = eval(e->gete2());
	else
		r = eval(e->gete3());
	}
  };
  V vis;
  e->accept(vis);
  return vis.r;
}
