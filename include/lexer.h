#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <sstream>

#include "token.h"

class Lexer 
{
	public:
		Lexer ( const std::string& );

		Token next_token ( );	//	Get next token from input buffer
		void consume ( );	//	Progress through input buffer

		bool is_letter ( );
		bool is_number ( );

		void WHITESPACE ( );
		Token _ID  ( );	//	Return ID Token
		Token _NUM ( );	//	Return NUM Token

		/*
		 *	TOKEN TYPES
		 * */
		static const char END_CHAR;

		static const unsigned char END;
		static const unsigned char LBRACK;
		static const unsigned char RBRACK;
		static const unsigned char EQUALS;
		static const unsigned char ID;
		static const unsigned char NUM;

		static std::string TAGS [ ];

	private:

		std::string	m_buffer;	//	Input string
		unsigned int 	m_index;	//	Current buffer index
		char 		m_current;	//	Current character
};
#endif
