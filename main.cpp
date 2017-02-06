#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "weight.hpp"
#include "height.hpp"

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
    print(e);
    std::cout << " == " << eval(e) << '\n';
    std::cout << "weight" << " == " << weight(e) << '\n';

   std::cout << "height" << " == " << height(e) << '\n';
    
  }
  {
	Expr* e =
		new Not_expr(new Bool_expr(true));
  
   std::cout << "weight" << " == " << weight(e) << '\n';}
}
