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
	case ")" :
	  {
	  consume();
	  return new Punctuator_Tok(RPara_Tok);
	  }
	case "+" :
	  {
	  consume();
	  return new Punctuator_Tok(Plus_Tok);
	  }
	case "-" :
	  {
	  consume();
	  return new Punctuator_Tok(Minus_Tok);
	  }
	case "*" :
	  {
	  consume();
	  return new Punctuator_Tok(Star_Tok);
	  }
	case "/" :
	  {
	  consume();
	  return new Punctuator_Tok(Slash_Tok);
	  }
	case "|" :
	  {
	  consume();
	  return new Punctuator_Tok(Pipe_Tok);
	  }
	case "&" :
	  {
	  consume();
	  return new Punctuator_Tok(Amp_Tok);
	  }
	case "%" :
	  {
	  consume();
	  return new Punctuator_Tok(Percent_Tok);
	  }
	case "!" :
	  {
	  consume();
	  if(lookahead() == "="){
		consume();
	  	return new Punctuator_Tok(Neq_Tok);
		}
	  else{
		return new Punctuator_Tok(Bang_Tok);
		}
	  }
	case "<" :
	  {
	  consume();
	  if(lookahead() == "="){
		consume();
		return new Punctuator_Tok(Lse_Tok);
	  }
	  else
	  	return new Punctuator_Tok(Lss_Tok);
	  }
	case ">" :
	  {
	  consume();
	  if(lookahead() == "="){
		consume();
		return new Punctuator_Tok(Gte_Tok);
	  }
	  else
	  	return new Punctuator_Tok(Gtr_Tok);
	  }
	case "=" :
	  {
	  consume();
	  if(lookahead() == "="){
		consume();
		return new Punctuator_Tok(Lse_Tok);
	  }
	  else
	  	return new Punctuator_Tok(Less_Tok);
	  }
	case " " :
		ignore();
		break();
	case "/t" :
		ignore();
		break();
	case "/n" :
		ignore();
		break();
	case "0" ... "9" :
	  {
	  const char* iter = first;
	  consume();
	  while(!eof() && std::digit(lookahead()){
		std::string str(iter, first);
		int n = std::stoi(str);
		return new Int_Tok(Int_Tok, n);
		}
	  }
	case "t" :
	  consume();
	  if(lookahead() == "r"){
		consume();
		if(lookahead() == "u"){
		consume();
			if(lookahead() == "e"){
				consume();
				return new Bool_Tok(Bool_Tok, 1);
				}
			else
				std::cout << "Error" << std::endl;
			}
		else
			std::cout << "Error" << std::endl;
		}
	  else
		std::cout << "Error" << std::endl;
	  }
	}
	case "f" :
	  {
	  consume();
	  if(lookahead() == "a"){
		consume();
		if(lookahead() == "l"){
		consume();
			if(lookahead() == "s"){
				consume();
				if(lookahead() == "e"){
					consume();
					return new Bool_Tok(Bool_Tok, 0);
					}
				else
					std::cout << "Error" << std::endl;
			}
			else
				std::cout << "Error" << std::endl;
		}
		else
			std::cout << "Error" << std::endl;
	  }
	  else
		std::cout << "Error" << std::endl;
	}
	
  }
};


