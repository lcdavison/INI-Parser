#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

#include <iostream>

class Parser 
{
	public:
		
		Parser ( Lexer );

		/*
		 *	Grammar rule for parsing file entries.
		 * */
		void entry ( );

		/*
		 *	Grammar rule for parsing section headers.
		 * */
		void section ( );

		/*
		 *	Grammar rule for parsing id assignments.
		 * */
		void assignment ( );

		/*
		 *	Matches a given token type with the current token
		 *	from the lexer.
		 * */
		void match ( unsigned char );

		/*
		 *	Progresses to the next token for parsing.
		 * */
		void consume ( );

	private:

		Lexer m_lexer;		//	Lexer providing the tokens
		Token m_current;	//	Current token for parsing
};
#endif
