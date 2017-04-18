#ifndef token_hpp
#define token_hpp
#include <string>
#include <unordered_map>


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
  Eof_Tok,
  //Data types
  Int_Tok,
  Bool_Tok,
  Id_Tok,

  //Keywords
  bool_kw,
  false_kw,
  int_kw,
  true_kw,
  var_kw
};

struct Token{
  int name;
  std::string value;
  Token(int n, std::string v) : name(n), value(v) {}
};

struct Integer_Tok : Token{
	Integer_Tok(std::string v) : Token(Int_Tok, v) {}
};

struct Boolean_Tok : Token{
	Boolean_Tok(std::string v) : Token(Bool_Tok, v) {}
};

// struct id_tok : Token{
//   id_tok(std::string* s) : Token(Id_Tok, s) {}
//
// };

struct keywordtable : std::unordered_map<std::string, Token_name>{
  keywordtable();
};

#endif
