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
#include <cstring>
#include <sstream>

#include "token.h"

class Lexer 
{
	public:
		Lexer ( const std::string& );

		/*
		 * 	Returns the next token from the input buffer.
		 * */
		Token next_token ( );

		/*
		 *	Progresses marker through the input buffer, 
		 *	updates current character.
		 * */
		void consume ( );

		/*
		 *	Matches a the current character with an expected character.
		 * */
		void match ( char );

		/*
		 *	Performs a test checking for alphabetical characters.
		 * */
		bool is_letter ( );

		/*
		 *	Performs a test checking for numerical characters.
		 * */
		bool is_number ( );

		/*
		 *	Lexical rule consuming any whitespace characters.
		 *	These include tabs, return carriages, and spaces.
		 * */
		void WHITESPACE ( );

		/*
		 *	Lexical rule for identifiers.
		 * */
		Token _ID  ( );

		/*
		 *	Lexical rule for strings.
		 * */
		Token _STRING ( );

		/*
		 *	Lexical rule for numbers.
		 * */
		Token _NUM ( );

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
		static const unsigned char STRING;

		static std::string TAGS [ ];

	private:

		std::string	m_buffer;	//	Input character buffer
		unsigned int 	m_index;	//	Current buffer index
		char 		m_current;	//	Current character
};
#endif
