#ifndef ast_hpp
#define ast_hpp

struct Expr {
  virtual ~Expr(){};
  Expr() {};
  virtual int weight() {};
  virtual int height() {};
  virtual bool Eval() {};
};

// struct False_Expr : Expr{
//     int weight()  {return 1;};
//     int height() {return 0;};
//     bool value = false;
//     bool Eval()  {return value;};
// };
//
// struct True_Expr : Expr{
//     int weight()  {return 1;};
//     int height() {return 0;};
//     bool value = true;
//     bool Eval()  {return value;};
// };

struct Bool_Expr : Expr{
    Bool_Expr(bool value) {Eval();};
    int weight() {return 1;};
    int height() {return 0;};
    bool value;
    bool Eval()  {return value;};
};

struct Not_Expr : Expr{
    Expr* e;
    Not_Expr(Expr *e) {Eval(e);};
    int weight()  {return 1 + e->weight();};
    int height()  {return 1 + e->height();};
    bool Eval(Expr* e)  {return  !e->Eval();};
};

struct And_Expr : Expr{
    Expr* e1;
    Expr* e2;
    And_Expr(Expr *e1, Expr *e2) {Eval(e1,e2);};
    int weight()  {return 1 + e1->weight() + e2->weight();};
    int height()  {return 1 + e1->height() + e2->height();};
    bool Eval(Expr *e1, Expr *e2)  {return e1->Eval() && e2->Eval();};
};

struct Or_Expr : Expr{
    Expr* e1;
    Expr* e2;
    Or_Expr(Expr *e1, Expr *e2) {Eval(e1, e2);};
    int weight()  {return 1 + e1->weight() + e2->weight();};
    int height()  {return 1 + e1->height() + e2->height();};
    bool Eval(Expr *e1, Expr *e2)  {return e1->Eval() || e2->Eval();};
};

struct Cond_Expr : Expr {
    Expr* e1;
    Expr* e2;
    Expr* e3;
    int weight()  {return 1 + e1->weight() + e2->weight() + e3->weight();};
    int height()  {return 1 + e1->height() + e2->height() + e3->height();};
    bool Eval()  { };
};

#endif
