

#include "token.hpp"
#include <string>
#include <cstring>

#include <iostream>

struct lexer{
  
  const char* first;
  const char* last;
  std::string buf;
  
  lexer(char* line) : first(line), last(&line[std::strlen(line)]) { }
  
  bool eof() const { return first == last; };
  
  char lookahead() const {

  	if(eof())
		return 0;
  	else
		return *first;
  	}


  void consume() {

    if(eof())
	return;
  
    buf = first++;
    //buf.back();
  }

  void ignore() {
    if(eof())
	return;
    *first++;
  }


  Token* next(){

  buf.clear();
  //std::isnewspace(lookahead());
  switch(lookahead()){
	case '#' :
		first == last;
		break;
	case '(' : 
	  {
	  consume();
	  return new Punctuator_Tok(LPara_Tok, buf);
	  }
	case ')' :
	  {
	  consume();
	  return new Punctuator_Tok(RPara_Tok, buf);
	  }
	case '+' :
	  {
	  consume();
	  return new Punctuator_Tok(Plus_Tok, buf);
	  }
	case '-' :
	  {
	  consume();
	  return new Punctuator_Tok(Minus_Tok, buf);
	  }
	case '*' :
	  {
	  consume();
	  return new Punctuator_Tok(Star_Tok, buf);
	  }
	case '/' :
	  {
	  consume();
		if(lookahead() == '/'){
			first == last;
			break;
			}
	  else
	  	return new Punctuator_Tok(Slash_Tok, buf);
	  }
	case '|' :
	  {
	  consume();
		if(lookahead() == '|'){
			consume();
			return new Punctuator_Tok(Or_Tok, buf);
			}
	  return new Punctuator_Tok(Pipe_Tok, buf);
	  }
	case '&' :
	  {
	  consume();
	  if(lookahead() == '&')
			consume();
			return new Punctuator_Tok(And_Tok, buf);
	  return new Punctuator_Tok(Amp_Tok, buf);
	  }
	case '%' :
	  {
	  consume();
	  return new Punctuator_Tok(Percent_Tok, buf);
	  }
	case '!' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
	  	return new Punctuator_Tok(Neq_Tok, buf);
		}
	  else{
		return new Punctuator_Tok(Bang_Tok, buf);
		}
	  }
	case '<' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
		return new Punctuator_Tok(Lse_Tok, buf);
	  }
	  else
	  	return new Punctuator_Tok(Lss_Tok, buf);
	  }
	case '>' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
		return new Punctuator_Tok(Gte_Tok, buf);
	  }
	  else
	  	return new Punctuator_Tok(Gtr_Tok, buf);
	  }
	case '=' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
		return new Punctuator_Tok(Eql_Tok, buf);
	  }
	  else
	  	std::cout << "Error =" << std::endl;
	  }
	case ' ' :
		ignore();
		break;
	case '\t' :
		ignore();
		break;
	case '\n' :
		ignore();
		break;
	case '0' ... '9' :
	  {
	  const char* iter = first;
	  consume();
	  while(!eof() && std::isdigit(lookahead())){
		std::string str(iter, first);
		int n = std::stoi(str);
		return new Int_Tok(n);
		}
	  }
	case 't' :
	{
	  consume();
	  if(lookahead() == 'r'){
		consume();
		if(lookahead() == 'u'){
		consume();
			if(lookahead() == 'e'){
				consume();
				return new Bool_Tok(1);
				}
			else
				std::cout << "Error true" << std::endl;
			}
		else
			std::cout << "Error true" << std::endl;
		}
	  else
		std::cout << "Error true" << std::endl;
	 }
	
	case 'f' :
	{
	  consume();
	  if(lookahead() == 'a'){
		consume();
		if(lookahead() == 'l'){
		consume();
			if(lookahead() == 's'){
				consume();
				if(lookahead() == 'e'){
					consume();
					return new Bool_Tok(0);
				}
				else
					std::cout << "Error e in false" << std::endl;
			}
			else
				std::cout << "Error s in false" << std::endl;
			}
		else
			std::cout << "Error l in false" << std::endl;
		}
	  else
		std::cout << "Error a in false" << std::endl;
	 }
	}
}
};


