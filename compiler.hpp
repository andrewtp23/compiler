#ifndef compiler_hpp
#define compiler_hpp

struct Expr {
  virtual ~Expr(){};
  virtual int weight() = 0;
  virtual int height() = 0;
  virtual bool Eval() = 0;

};

struct True_Expr : Expr{
    int weight()  {return 1;};
    bool Eval()  {return true;};
};

struct False_Expr : Expr{
    int weight()  {return 1;};
    bool Eval()  {return false;};
};

struct Not_Expr : Expr{
    Expr* e;
    int weight()  {return 1 + e->weight();};
    int height()  {return 1 + e->height();};
    bool Eval()  {return  !e->Eval();}
};

struct And_Expr : Expr{
    Expr* e1;
    Expr* e2;
    int weight()  {return 1 + e1->weight() + e2->weight();};
    int height()  {return 1 + e1->height() + e2->height();};
    bool Eval()  {return e1->Eval() && e2->Eval();}
};

struct Or_Expr : Expr{
    Expr* e1;
    Expr* e2;
    int weight()  {return 1 + e1->weight() + e2->weight();};
    int height()  {return 1 + e1->height() + e2->height();};
    bool Eval()  {return e1->Eval() || e2->Eval();}
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
