#include <string>
#include "token.hpp"

struct Lexer{

  const char* first;
  const char* last;
  std::string buf;
  bool eof() const { return first == last; };
  char lookahead() const {

  if(eof())
	return 0;
  else
	return *first;
  }

  void consume() {

    if(eof())
	return 0;
  
    buf = first++;
    return buf.back();
  }

  void ignore() {
    if(eof())
	return 0;
    return *first++;
  }

  Token* next(){

  buf.clear();
  std::isnewspace(lookahead());
  switch{
	case "(" : 
	  {
	  consume();
	  return new Punctuator_Tok(LPara_Tok);
	  }

  }
};


