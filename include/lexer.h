/*
   Copyright (C) 2020  Luke Davison

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>
*/

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
		static const unsigned char NEWLINE;
		static const unsigned char ID;
		static const unsigned char NUM;

		static std::string TAGS [ ];

	private:

		std::string	m_buffer;	//	Input string
		unsigned int 	m_index;	//	Current buffer index
		char 		m_current;	//	Current character
};
#endif
