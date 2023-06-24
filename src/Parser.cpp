# include "Tokens.hpp"
# include "Parser.hpp"
# include <iostream>

/* This function handles:
   1. (Expression). Priority 0
   2. unary logical operator NOT. Priority 1
   3. unary bitwise complement operator ~ . Priority 2
*/
int Primary(){

	tStream>>Tok;
	
	switch (Tok.Operation){

	// Handle '(' Expression ')'
	case ('('): { int Result = Expression();
		      tStream>>Tok;
		      if (Tok.Operation !=')') 
			      throw std::runtime_error("Expected ')' in your expression.");
		      tStream<<Tok;
      		      return Result;
		    }

	// Handle unary logical operator NOT
	case ('!'): { int Result = Expression();
		      return !Result;
		    }
	// Handle unary bitwise complement operator ~
	case ('~'): { int Result = Expression();
		      return ~Result;
		    }
	// Return Operand
	case ('N'): { int Number = Tok.Operand;
		      return Number;
		    }
	default:
		throw std::runtime_error("I don't know this operation or operand");
	}
}

   
/* This function handles:
   1. binary bitwise operator AND. Priority 3
*/
int firstTerm(){

	int lValue = Primary();

	while(true){ tStream>>Tok;

	   switch (Tok.Operation){

	        case('&'):	lValue &=Primary();   break;

		default  :      tStream<<Tok; 	      return lValue;
	   }
	}
}

/* This function handles:
   1. binary bitwise operator XOR. Priority 4
*/
int secondTerm(){

	int lValue = firstTerm();

	while(true){ tStream>>Tok;

	   switch (Tok.Operation){

	        case('^'):	lValue ^=firstTerm();   break;

		default  :      tStream<<Tok; 	      	    return lValue;
	   }
	}

}

/* This function handles:
   1. binary bitwise operator OR. Priority 5
*/
int Expression(){

 	int lValue = secondTerm();

 	while (true){ tStream>>Tok;

	   switch(Tok.Operation){

		case('|'):     lValue |=secondTerm();  break;

		default  :     tStream<<Tok;	           return lValue;
	   }
	}
}
