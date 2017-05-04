#ifndef lexer_hpp
#define lexer_hpp

#include "token.hpp"
#include "symbols.hpp"
#include <string>
#include <cstring>

#include <iostream>

struct lexer{

  const char* first;
  const char* last;
  std::string buf;
  const keyword_table* keywords;
  symbol_table* symbols;

  lexer(char* line, keyword_table *keywords, symbol_table *syms) : first(line), last(&line[std::strlen(line)]), keywords(kw), symbols(syms) { }

  bool eof() const { return first == last; };

  char lookahead() const {

  	if(eof())
		return 0;
  	else
		return *first;
  	}

	bool match_letter(char c){
		return (std::isalpha(c) || c == '_');
	}

	bool match_letter_digit(char c){
		return (std::isdigit(c) || std::isalpha(c) || c == '_');
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
	  return new Token(LPara_Tok, buf );
	  }
	case ')' :
	  {
	  consume();
	  return new Token(RPara_Tok, buf );
	  }
	case '+' :
	  {
	  consume();
	  return new Token(Plus_Tok, buf );
	  }
	case '-' :
	  {
	  consume();
	  return new Token(Minus_Tok, buf );
	  }
	case '*' :
	  {
	  consume();
	  return new Token(Star_Tok, buf );
	  }
	case '/' :
	  {
	  consume();
		if(lookahead() == '/'){
			first == last;
			break;
			}
	  else
	  	return new Token(Slash_Tok, buf );
	  }
	case '|' :
	  {
	  consume();
		if(lookahead() == '|'){
			consume();
			return new Token(Or_Tok, buf );
			}
	  return new Token(Pipe_Tok, buf );
	  }
	case '&' :
	  {
	  consume();
	  if(lookahead() == '&')
			consume();
			return new Token(And_Tok, buf );
	  return new Token(Amp_Tok, buf );
	  }
	case '%' :
	  {
	  consume();
	  return new Token(Percent_Tok, buf );
	  }
	case '!' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
	  	return new Token(Neq_Tok, buf );
		}
	  else{
		return new Token(Bang_Tok, buf );
		}
	  }
	case '<' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
		return new Token(Lse_Tok, buf );
	  }
	  else
	  	return new Token(Lss_Tok, buf );
	  }
	case '>' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
		return new Token(Gte_Tok, buf );
	  }
	  else
	  	return new Token(Gtr_Tok, buf );
	  }
	case '=' :
	  {
	  consume();
	  if(lookahead() == '='){
		consume();
		return new Token(Eql_Tok, buf );
	  }
	  else
	  	return new Token(Assign_Tok, buf);

		break;
	  }
	case '?' :
	{
		consume();
		return new Token(Cond_Tok, buf);
		break;
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
		return new Integer_Tok(str);
		}
	  }
	// case 't' :
	// {
	//   consume();
	//   if(lookahead() == 'r'){
	// 	consume();
	// 	if(lookahead() == 'u'){
	// 	consume();
	// 		if(lookahead() == 'e'){
	// 			consume();
	// 			return new Boolean_Tok("true");
	// 			}
	// 		else
	// 			std::cout << "Error true" << std::endl;
	// 		}
	// 	else
	// 		std::cout << "Error true" << std::endl;
	// 	}
	//   else
	// 	std::cout << "Error true" << std::endl;
	//  }
  //
	// case 'f' :
	// {
	//   consume();
	//   if(lookahead() == 'a'){
	// 	consume();
	// 	if(lookahead() == 'l'){
	// 	consume();
	// 		if(lookahead() == 's'){
	// 			consume();
	// 			if(lookahead() == 'e'){
	// 				consume();
	// 				return new Boolean_Tok("false");
	// 			}
	// 			else
	// 				std::cout << "Error e in false" << std::endl;
	// 		}
	// 		else
	// 			std::cout << "Error s in false" << std::endl;
	// 		}
	// 	else
	// 		std::cout << "Error l in false" << std::endl;
	// 	}
	//   else
	// 	std::cout << "Error a in false" << std::endl;
	//  }
	default:
		if(match_letter(lookahead()))
			return word();
		else
			break;
	}
}

Token* word(){
	consume();
	while(!eof() && match_letter_digit(lookahead()))
		consume();

	auto key = keywords->find(buf);
	if(key != keywords->end())
	{
		Token* ntok = new Token(key->second);
		return ntok;
	}

	symbol* ns = symbols->insert(buf);
	Token* ntok = new ID_Tok(ns);
	return ntok;
}
};

#endif
