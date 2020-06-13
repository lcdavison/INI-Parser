#include "lexer.h"

const char Lexer::END_CHAR = ( char ) -1;

const unsigned char Lexer::END 	  = 0;
const unsigned char Lexer::LBRACK = 1;
const unsigned char Lexer::RBRACK = 2;
const unsigned char Lexer::EQUALS = 3;
const unsigned char Lexer::ID 	  = 4;
const unsigned char Lexer::NUM 	  = 5;

std::string Lexer::TAGS [ 6 ] = { "<EOF>", "[", "]", "=", "ID", "NUM" };

Lexer::Lexer ( const std::string& p_input ) : m_buffer ( p_input ), m_index ( 0 ), m_current ( p_input [ 0 ] ) { }

Token Lexer::next_token ( )
{
	while ( m_current != Lexer::END_CHAR )
	{
		switch ( m_current )
		{
			case '\n':
			case '\t':
			case '\r':
			case ' ':
				WHITESPACE ( );
				continue;
			case '[':
				consume ( );
				return Token ( "[", Lexer::LBRACK );
			case ']':
				consume ( );
				return Token ( "]", Lexer::RBRACK );
			case '=':
				consume ( );
				return Token ( "=", Lexer::EQUALS );
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

void Lexer::WHITESPACE ( )
{
	if ( m_current == '\n' || m_current == '\t' || m_current == '\r' || m_current == ' ' ) consume ( );
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