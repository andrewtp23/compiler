#ifndef token_hpp
#define token_hpp
#include <string>

struct Token{
  int name;
  
};

struct Punctuator_Tok : Token { 
  int name;
  std::string value;
  Punctuator_Tok(int n, std::string v) : name(n), value(v) {}
};

struct Int_Tok : Token{
	int value;

	Int_Tok(int n) : value(n) { }
};

struct Bool_Tok : Token{
	bool value;

	Bool_Tok(int n) : value(n) { }
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
  And_Tok
  
};

#endif
