#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

#include <iostream>

class Parser 
{
	public:
		
		Parser ( Lexer );

		void entry ( );
		void section ( );
		void assignment ( );

		void match ( unsigned char );
		void consume ( );

	private:

		Lexer m_lexer;
		Token m_current;
};
#endif
