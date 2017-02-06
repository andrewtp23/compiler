#ifndef ast_HPP
#define ast_HPP

#include <cassert>

struct Bool_type;
struct Int_type;

struct Bool_expr;
struct And_expr;
struct Or_expr;
struct Not_expr;
struct Gtr_expr;
struct Lss_expr;
struct Grq_expr;
struct Leq_expr;
struct Eql_expr;
struct Neq_expr;
struct Int_expr;
struct Add_expr;
struct Sub_expr;
struct Mul_expr;
struct Div_expr;
struct Mod_expr;
struct Neg_expr;

struct Type {
  struct Visitor;
  virtual ~Type() {};
  virtual void accept(Visitor&) { }
};

struct Bool_type : Type { };
struct Int_type : Type { };

struct Expr {
  struct Visitor;
  virtual ~Expr() {};
  virtual void accept(Visitor&) = 0;
};

struct Expr::Visitor
{
  virtual void visit(Bool_expr*) = 0;
  virtual void visit(And_expr*) = 0;
  virtual void visit(Or_expr*) = 0;
  virtual void visit(Not_expr*) = 0;
  virtual void visit(Gtr_expr*) = 0;
  virtual void visit(Lss_expr*) = 0;
  virtual void visit(Grq_expr*) = 0;
  virtual void visit(Leq_expr*) = 0;
  virtual void visit(Eql_expr*) = 0;
  virtual void visit(Neq_expr*) = 0;
  virtual void visit(Int_expr*) = 0;
  virtual void visit(Add_expr*) = 0;
  virtual void visit(Sub_expr*) = 0;
  virtual void visit(Mul_expr*) = 0;
  virtual void visit(Div_expr*) = 0;
  virtual void visit(Mod_expr*) = 0;
  virtual void visit(Neg_expr*) = 0;
};

struct Bool_expr : Expr {
  bool val;//Don't touch this
  Bool_expr(bool b) : val(b) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct And_expr : Expr {
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  And_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Or_expr : Expr {
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Or_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Not_expr : Expr {
  Expr* e1; //Don't touch this
  public:
  Not_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Gtr_expr : Expr { //greater than
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Gtr_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Lss_expr : Expr { //lessthan
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Lss_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Grq_expr : Expr { //greater or equal
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Grq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Leq_expr : Expr { //lessthan or equal
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Leq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Eql_expr : Expr { //eql
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Eql_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Neq_expr : Expr { //not eql also xor
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  public:
  Neq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Int_expr : Expr {
  int val;//Don't touch this
  Int_expr(int b) : val(b) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct Add_expr : Expr {
  Expr* e1; //Don't touch this. I know you wanted to.
  Expr* e2; //Don't touch this
  public:
  Add_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Sub_expr : Expr {
  Expr* e1; //Don't touch this. I know you wanted to.
  Expr* e2; //Don't touch this
  public:
  Sub_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Mul_expr : Expr {
  Expr* e1; //Don't touch this. I know you wanted to.
  Expr* e2; //Don't touch this
  public:
  Mul_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Div_expr : Expr {
  Expr* e1; //Don't touch this. I know you wanted to.
  Expr* e2; //Don't touch this
  public:
  Div_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Mod_expr : Expr {
  Expr* e1; //Don't touch this. I know you wanted to.
  Expr* e2; //Don't touch this
  public:
  Mod_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Neg_expr : Expr {
  Expr* e1; //Don't touch this. I know you wanted to.
  public:
  Neg_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Context
{
 public:
  Bool_type bool_type;
  Int_type int_type;
};

#endif
