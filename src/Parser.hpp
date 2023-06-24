/* Syntax analizer the these rules:
	Expression:
		secondTerm
		Expression OR secondTerm
	secondTerm:
		firstTerm
		secondTerm XOR firstTerm
	firstTerm:
		Primary
		firstTerm AND Primary
	Primary:
		'(' Expression ')'
		  ! Expression
		  ~ Expression
		  Number
	Number:
		integer
*/
# ifndef _PARSER_
# define _PARSER_


// Priority 5. Handle binary bitwise operator OR
int Expression();

// Priority 4. Handle binary bitwise operator XOR
int secondTerm();

// Priority 3. Handle binary bitwise operator AND
int firstTerm();

// Prioriry 2. Handle unary bitwise complement operator ~
// Priority 1. Handle unary logical operator NOT
// Priority 0. Handle '(' Expression ')'
int Primary();

# endif
