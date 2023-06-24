# include "Tokens.hpp"
# include <iostream>

/* ====================== Definitions our methods =============================== */

// For copy this token into token stream
Token& Token::operator=(const Token &Src){
	Operation = Src.Operation;
	Operand = Src.Operand;
return *this;
}

// We get our token from input stream (aka console)
void Token::Get(){
	char UncnownToken{'0'};
	std::cin>>UncnownToken;
	switch(UncnownToken){
		case '&': case '|': case '=': case '(': case ')': case '!': case '~': case '^':
	     		std::cin.putback(UncnownToken);
	     		std::cin>>Operation;
	     		Operand = 'O'; // The value O means that this token is an operation
	     	break;
	        case '0': case '1': case '2': case '3': case '4':
	        case '5': case '6': case '7': case '8': case '9':
	     		std::cin.putback(UncnownToken);
	     		std::cin>>Operand;
	     		Operation='N'; // The value N means this token is a value 
	     	break;
	   	default:
	     		throw std::runtime_error("I don't know this operator or operand");
	}

}

// We put token into token stream
TokenStream& TokenStream::operator<<(Token &SourceTok){
	if(isEmpty) { Buffer=SourceTok; isEmpty=false;}
return *this;
}

// We get token from token stream or input stream
TokenStream& TokenStream::operator>>(Token &DistTok){
	if(!isEmpty) { DistTok = Buffer; isEmpty=true; } // Get tok from token stream
	else { DistTok.Get();isEmpty=true; } // Get tok from input stream
return *this;
}
