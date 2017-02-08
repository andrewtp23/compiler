#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "weight.hpp"
#include "height.hpp"
#include "type.hpp"

int
main() {
  Context cxt;
  {
    Expr* e =
	new And_expr( new Not_expr( new Bool_expr(true) ), new Bool_expr(true) );
    print(e);
    check(cxt, e);
    std::cout << " == " << eval(e) << '\n';
	std::cout << "weight" << " == " << weight(e) << '\n';
	std::cout << "height" << " == " << height(e) << '\n';
  }

  {
    Expr* e =
      new Not_expr( new Or_expr( new Bool_expr(true), new Bool_expr(false)) );
    print(e);
    check(cxt, e);
    std::cout << " == " << eval(e) << '\n';
    std::cout << "weight" << " == " << weight(e) << '\n';

   std::cout << "height" << " == " << height(e) << '\n';

  }

  {
   Expr* e =
     new Add_expr(new Sub_expr(new Mul_expr(new Int_expr(2), new Int_expr(2)), new Int_expr(1)), new Int_expr(2));
	print(e);
	check(cxt, e);
	std::cout << " = " << eval(e) << '\n';
	std::cout << "weight" << " == " << weight(e) << '\n';
	std::cout << "height" << " == " << height(e) << '\n';
 }
 {
   Expr* e = 
	new Gtr_expr(new Add_expr( new Int_expr(4), new Mod_expr( new Int_expr(4), new Int_expr(2) )), new Neg_expr( new Int_expr(1)));
	print(e);
	check(cxt, e);
	std::cout << " = " << eval(e) << '\n';
	std::cout << "weight" << " == " << weight(e) << '\n';
	std::cout << "height" << " == " << height(e) << '\n';
 }
 
 {
   Expr* e = 
	new Cond_expr( new Not_expr( new Bool_expr(true)), new Bool_expr(false), new Not_expr( new Bool_expr(false)));
	print(e);
	check(cxt, e);
	std::cout << " = " << eval(e) << '\n';
	std::cout << "weight" << " == " << weight(e) << '\n';
	std::cout << "height" << " == " << height(e) << '\n';
 }
}
