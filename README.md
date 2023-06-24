# CPP_CalcBit
This is a simply bitwise calculator.

==========================================
Descriptions of using and installation:  +
==========================================
1. Run make utility. You'll get binary-file;
2. Run binary-file such as CalcBitwise;
3. If you need to install this calculator then;
you need to run this command such as "make install" after item one;
4. If you need to uninstall it then yoy need
you need to run the command such as "make uninstall" after item three;
5. At the end you can delete all the resulting files after item one.

=========================================
Description of the programm		+
=========================================
1. We get token from input-stream
The type Token declare in the Token.cpp and
define in the Token.hpp;

2. We put this token in token-stream.
The algorithm works with it.
The type TokenStream declare in the TokenStream.cpp and
define in the Token.hpp;

3. Each token is parsed accordint to rules.
These rulse is descripted in Parser. You can look at bellow.
The parser declare in the Parser.cpp and
define in the Parser.hpp.

The rules:
1) Priority 5. Handle binary bitwise operator OR
	Expression:
		secondTerm
		Expression OR secondTerm

2) Priority 4. Handle binary bitwise operator XOR
	secondTerm:
		firstTerm
		secondTerm XOR firstTerm

3) Priority 3. Handle binary bitwise operator AND
	firstTerm:
		Primary
		firstTerm AND Primary


4) Prioriry 2. Handle unary bitwise complement operator ~
   Priority 1. Handle unary logical operator NOT
   Priority 0. Handle '(' Expression ')'
	Primary:
		'(' Expression ')'
		  ! Expression
		  ~ Expression
		  Number
	Number:
		integer
