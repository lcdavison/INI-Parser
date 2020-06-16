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

#include "lexer.h"

#include <iostream>

const char Lexer::END_CHAR = ( char ) -1;

const unsigned char Lexer::END 	   = 0;
const unsigned char Lexer::LBRACK  = 1;
const unsigned char Lexer::RBRACK  = 2;
const unsigned char Lexer::EQUALS  = 3;
const unsigned char Lexer::NEWLINE = 4;
const unsigned char Lexer::ID 	   = 5;
const unsigned char Lexer::NUM 	   = 6;
const unsigned char Lexer::STRING  = 7;

std::string Lexer::TAGS [ 8 ] = { "<EOF>", "[", "]", "=", "NEWLINE", "ID", "NUM", "STRING" };

Lexer::Lexer ( const std::string& p_input ) : m_buffer ( p_input ), m_index ( 0 ), m_current ( p_input [ 0 ] ) { }

Token Lexer::next_token ( )
{
	while ( m_current != Lexer::END_CHAR )
	{
		switch ( m_current )
		{
			case '\t':
			case '\r':
			case ' ':
				WHITESPACE ( );
				continue;
			case '\n':
				consume ( );
				return Token ( "NEWLINE", Lexer::NEWLINE );
			case '[':
				consume ( );
				return Token ( "LBRACK", Lexer::LBRACK );
			case ']':
				consume ( );
				return Token ( "RBRACK", Lexer::RBRACK );
			case '=':
				consume ( );
				return Token ( "EQUALS", Lexer::EQUALS );
			case '"':
				return _STRING ( );
			default:
				if ( is_letter ( ) ) return _ID ( );
				if ( is_number ( ) || m_current == '.' ) return _NUM ( );
		}
	}

	return Token ( Lexer::TAGS [ Lexer::END ], Lexer::END );
}

void Lexer::consume ( )
{
	++m_index;

	if ( m_index == m_buffer.size ( ) ) 
		m_current = Lexer::END_CHAR;
	else
		m_current = m_buffer [ m_index ];
}

void Lexer::match ( char p_expected )
{
	if ( m_current == p_expected ) 
		consume ( );
	else
	{
		std::string error = "Expected : ";
		error.push_back ( p_expected );
		error.append ( " Found : " );
		error.push_back ( m_current );

		throw error;
	}
}

void Lexer::WHITESPACE ( )
{
	while ( m_current == '\t' || m_current == '\r' || m_current == ' ' ) consume ( );
}

Token Lexer::_ID ( )
{
	std::stringstream ss;

	do
	{
		ss << m_current;
		consume ( );
	} 
	while ( is_letter ( ) );

	return Token ( ss.str ( ), Lexer::ID );	
}

Token Lexer::_STRING ( )
{
	match ( '"' );

	std::stringstream ss;

	do
	{
		ss << m_current;
		consume ( );
	}
	while ( is_letter ( ) || m_current == ' ' );

	match ( '"' );

	return Token ( ss.str ( ), Lexer::STRING );
}

Token Lexer::_NUM ( )
{
	std::stringstream ss;

	do
	{
		ss << m_current;
		consume ( );
	} 
	while ( is_number ( ) || m_current == '.' );

	return Token ( ss.str ( ), Lexer::NUM );	
}

bool Lexer::is_letter ( )
{
	return ( m_current >= 'a' && m_current <= 'z' || m_current >= 'A' && m_current <= 'Z' );
}

bool Lexer::is_number ( )
{
	return ( m_current >= '0' && m_current <= '9' );
}
