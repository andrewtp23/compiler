#include <iostream>
#include "compiler.hpp"

int main()
{
 Expr* e = new And_Expr(new Not_Expr(new Bool_Expr(true)), new Bool_Expr(false));
 std::cout << e << std::endl;

	return 0;
}
