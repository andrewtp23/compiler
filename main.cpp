
#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "check.hpp"

int 
main() {
  Context cxt;
  {
    Expr* e = 
      new Or_expr(
        new Not_expr(
          new Bool_expr(true)
        ),
        new Bool_expr(true)
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e) << '\n';
  }

  {
    Expr* e = 
      new Not_expr(
        new Or_expr(
          new Bool_expr(true),
          new Bool_expr(false)
        )
      );
    assert(check(cxt, e));
    print(e);
    std::cout << " == " << eval(e) << '\n';
  }
}
