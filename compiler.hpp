#ifndef compiler_hpp
#def compiler_hpp

struct Expr {
  virtual ~expr(){};
  virtual int weight() = 0;
  virtual int height() = 0;
  virtual Bool Eval() = 0;

};

struct True_Expr : Expr{
    int weight() override {return 1;};
    Bool Eval() override {return true;};
};

struct False_Expr : Expr{
    int weight() override {return 1;};
    Bool Eval() override {return false;};
};

struct Not_Expr : Expr{
    Expr* e;
    int weight() override {return 1 + e->weight();};
    int height() override {return 1 + e->height();};
    Bool Eval() override {return NOT e->Eval();}
};

struct And_Expr : Expr{
    Expr* e1;
    Expr* e2;
    int weight() override {return 1 + e1->weight() + e2->weight();};
    int height() override {return 1 + e1->height() + e2->height();};
    Bool Eval() override {return e1->Eval() && e2->Eval();}
};

struct Or_Expr : Expr{
    Expr* e1;
    Expr* e2;
    int weight() override {return 1 + e1->weight() + e2->weight();};
    int height() override {return 1 + e1->height() + e2->height();};
    Bool Eval() override {return e1->Eval() || e2->Eval();}
};

struct Cond_Expr : Expr {
    Expr* e1;
    Expr* e2;
    Expr* e3;
    int weight() override {return 1 + e1->weight() + e2->weight() + e3->weight();};
    int height() override {return 1 + e1->height() + e2->height() + e3->height();};
    Bool Eval() override {return }
};

#endif
