# ifndef _CALC_BITWISE_
# define _CALC_BITWISE_
/* ========== Declaration. This class is a token. It gets and checks. =========== */
class Token{
	public:
// We save our token in these variables
	char Operation{0};
	int Operand{0};
// We get our token from input stream (aka console)
	void Get();
// For copy this token into token stream
	Token& operator=(const Token &Src);
};

/* ======= Declaration. This class store token. It can get or put token. ======== */
class TokenStream {
	private:
		Token Buffer;
		bool isEmpty{true};
	public:
// We put token into token stream
		TokenStream& operator<<(Token &Tok_);
// We get token from token stream or input stream
		TokenStream& operator>>(Token &Tok_);
};

extern Token Tok;
extern TokenStream tStream;

# endif
