#ifndef token_hpp
#define token_hpp
#include <string>

struct Token{
  int name;
  std::string value;
  Token(int n, std::string v) : name(n), value(v) {}
};

struct Integer_Tok : Token{
	Integer_Tok(std::string);
};

struct Boolean_Tok : Token{
	Boolean_Tok(std::string);
};

enum Token_name {

  LPara_Tok,
  RPara_Tok,
  Plus_Tok,
  Minus_Tok,
  Star_Tok, //mul
  Slash_Tok, //division
  Pipe_Tok, //Or
  Amp_Tok, //And
  Bang_Tok, //not
  Gtr_Tok,
  Lss_Tok,
  Gte_Tok,
  Lse_Tok,
  Eql_Tok,
  Percent_Tok, //Modulus
  Or_Tok,
  Neq_Tok,
  Cond_Tok,
  Oth_Tok,
  And_Tok,
  //Data types
  Int_Tok,
  Bool_Tok

  //Keywords

};

#endif
