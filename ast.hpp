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
struct Ae_expr;
struct Cond_expr;
struct Oe_expr;

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
  Type* Ty;
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
  virtual void visit(Ae_expr*) = 0;
  virtual void visit(Cond_expr*) = 0;
  virtual void visit(Oe_expr*) = 0;
};

struct Bool_expr : Expr {
  private:
  bool val;//Don't touch this
  public:
  bool getval() { return val; };
  Bool_expr(bool b) : val(b) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct And_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  And_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Or_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Or_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Not_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Not_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Gtr_expr : Expr { //greater than
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Gtr_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Lss_expr : Expr { //lessthan
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Lss_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Grq_expr : Expr { //greater or equal
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Grq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Leq_expr : Expr { //lessthan or equal
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Leq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Eql_expr : Expr { //eql
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Eql_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Neq_expr : Expr { //not eql also xor
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Neq_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Int_expr : Expr {
  private:
  int val;//Don't touch this
  public:
  int getval() { return val; };
  Int_expr(int b) : val(b) {}
  void accept(Visitor& v) { return v.visit(this); }
};

struct Add_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Add_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Sub_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Sub_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Mul_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Mul_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Div_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Div_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Mod_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Mod_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Neg_expr : Expr {
  private:
  Expr* e1;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Neg_expr(Expr* e1) : e1(e1) { }
  void accept(Visitor& v) {return v.visit(this); }
};

struct Ae_expr : Expr { //and else
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Ae_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Cond_expr : Expr { //and else
  private:
  Expr* e1; // Don't touch this
  Expr* e2; // Don't touch this
  Expr* e3; // Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Expr* gete3() { return e3; };
  Cond_expr(Expr* e1, Expr* e2, Expr* e3) : e1(e1), e2(e2), e3(e3) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Oe_expr : Expr { //or else
  private:
  Expr* e1;//Don't touch this
  Expr* e2;//Don't touch this
  public:
  Expr* gete1() { return e1; };
  Expr* gete2() { return e2; };
  Oe_expr(Expr* e1, Expr* e2) : e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

struct Context
{
 public:
  Bool_type bool_type;
  Int_type int_type;
};

#endif
