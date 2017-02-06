#include "ast.hpp"
#include <iostream>

bool needs_parens(Expr* e)
{
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = false; }
    void visit(And_expr* e) { r = true; }
    void visit(Or_expr* e) { r = true; }
    void visit(Not_expr* e) { r = true; }
    void visit(Gtr_expr* e) { r = true; }
    void visit(Lss_expr* e) { r = true; }
    void visit(Grq_expr* e) { r = true; }
    void visit(Leq_expr* e) { r = true; }
    void visit(Eql_expr* e) { r = true; }
    void visit(Neq_expr* e) { r = true; }
    void visit(Int_expr* e) { r = false; }
    void visit(Add_expr* e) { r = true; }
    void visit(Sub_expr* e) { r = true; }
    void visit(Mul_expr* e) { r = true; }
    void visit(Div_expr* e) { r = true; }
    void visit(Mod_expr* e) { r = true; }
    void visit(Neg_expr* e) { r = false; }
    void visit(Ae_expr* e) { r = true; }
  };
  V vis;
  e->accept(vis);
  return vis.r;
}

void print(Expr* e)
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
    void visit(Gtr_expr* e) {
      print_enclosed(e->e1);
      std::cout << " > ";
      print_enclosed(e->e2);
    }
    void visit(Lss_expr* e) {
      print_enclosed(e->e1);
      std::cout << " < ";
      print_enclosed(e->e2);
    }
    void visit(Grq_expr* e) {
      print_enclosed(e->e1);
      std::cout << " >= ";
      print_enclosed(e->e2);
    }
    void visit(Leq_expr* e) {
      print_enclosed(e->e1);
      std::cout << " <= ";
      print_enclosed(e->e2);
    }
    void visit(Eql_expr* e) {
      print_enclosed(e->e1);
      std::cout << " == ";
      print_enclosed(e->e2);
    }
    void visit(Neq_expr* e) {
      print_enclosed(e->e1);
      std::cout << " != ";
      print_enclosed(e->e2);
    }
    void visit(Int_expr* e) {
      std::cout << e->val;
    }
    void visit(Add_expr* e) {
      print_enclosed(e->e1);
      std::cout << " + ";
      print_enclosed(e->e2);
    }
    void visit(Sub_expr* e) {
      print_enclosed(e->e1);
      std::cout << " - ";
      print_enclosed(e->e2);
    }
    void visit(Mul_expr* e) {
      print_enclosed(e->e1);
      std::cout << " * ";
      print_enclosed(e->e2);
    }
    void visit(Div_expr* e) {
      print_enclosed(e->e1);
      std::cout << " / ";
      print_enclosed(e->e2);
    }
    void visit(Mod_expr* e) {
      print_enclosed(e->e1);
      std::cout << " % ";
      print_enclosed(e->e2);
    }
    void visit(Neg_expr* e) {
      std::cout << " -";
      print_enclosed(e->e1);
    }
    void visit(Ae_expr* e) {
      print_enclosed(e->e1);
      std::cout << " && ";
      print_enclosed(e->e2);
    }
  };
  V vis;
  e->accept(vis);
}
