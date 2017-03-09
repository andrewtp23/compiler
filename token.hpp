

struct Token{
  int name;
};

struct Punctuator : Token {
  Boolean : Token { bool val; }
  Integer : Token { int val; }
};

struct Int_Tok{
	int value;
	Int_Tok(int tok, int n) : value(n), name(Int_Tok) { }
};

struct Bool_Tok{
	bool value;
	Bool_Tok(int tok, int n) : value(n), name(Bool_Tok) { }
};
enum Token.name {

  LPara_Tok;
  RPara_Tok;
  Plus_Tok;
  Minus_Tok;
  Star_Tok; //mul
  Slash_Tok; //division
  Pipe_Tok; //Or
  Amp_Tok; //And
  Bang_Tok; //not
  Gtr_Tok;
  Lss_Tok;
  Gte_Tok;
  Lse_Tok;
  Eql_Tok;
  Percent_Tok; //Modulus
  Or_Tok;
  And_Tok;
  
};
