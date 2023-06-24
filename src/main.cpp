# include "Tokens.hpp"
# include "Parser.hpp"
# include <iostream>

// Declare Token and token-stream
Token Tok;
TokenStream tStream;



int main(){

// Welcome and Note
	std::cout<<"\tWelcome!!! This is a Symply Calculator!\n"
		 <<"Note:\n" 
		 <<"1. You need to use operators such as: !, ~, & and |;\n"
		 <<"2. Enter the expression for the calculation;\n"
		 <<"3. Enter '=' in the end of the expression.\n";
// Calculate
try{
    std::cout<<Expression()<<std::endl;
   } 

// Error handle
catch(const std::exception& err){
	std::cerr<<"Err : "<<err.what()<<'\n';
}
return 0;
}
