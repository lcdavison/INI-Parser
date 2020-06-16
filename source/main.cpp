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

#include <iostream>

#include "token.h"
#include "reader.h"
#include "lexer.h"
#include "parser.h"

/*
 * 	Parsing Grammar =>
 * 		entry : ((assignment | section)? "\n")*
 *		assignment : ID '=' ( ID | STRING | NUM )?
 *		section : '[' ID ']'
 * */

int main ( int argc, char* argv [ ] )
{
	Reader reader ( "test.ini" );

	if ( !reader.is_open ( ) )
	{
		std::cout << "File Not Opened" << std::endl;
		return 1;
	}

	std::string content = reader.read ( );

	Lexer ini_lexer ( content );

	Parser ini_parser ( ini_lexer );

	try
	{
		ini_parser.entry ( );
	}
	catch ( std::string msg )
	{
		std::cout << msg << std::endl;
	}

	return 0;
}
