#include "parser.h"

Parser::Parser ( Lexer p_lexer ) : m_lexer ( p_lexer ) 
{
	m_current = m_lexer.next_token ( );
}

void Parser::entry ( ) 
{
	while ( m_current.m_id == Lexer::LBRACK || m_current.m_id == Lexer::ID )
	{
		if ( m_current.m_id == Lexer::LBRACK )
		{
			section ( );	
		}
		else if ( m_current.m_id == Lexer::ID )
		{
			assignment ( );
		}

		match ( Lexer::NEWLINE );
	}
}

void Parser::section ( )
{
	match ( Lexer::LBRACK );
	match ( Lexer::ID );
	match ( Lexer::RBRACK );
}

void Parser::assignment ( )
{
	match ( Lexer::ID );
	match ( Lexer::EQUALS );

	if ( m_current.m_id == Lexer::ID )
	{
		match ( Lexer::ID );
	}
	else if ( m_current.m_id == Lexer::STRING )
	{
		match ( Lexer::STRING );
	}
	else if ( m_current.m_id == Lexer::NUM )
	{
		match ( Lexer::NUM );
	}
	else
	{
		throw "Expected ID or NUM, found : " + Lexer::TAGS [ m_current.m_id ];
	}
}

void Parser::match ( unsigned char p_type )
{
	if ( m_current.m_id == p_type )
	{
		std::printf ( "Matched : %-10s | %+10s\n", Lexer::TAGS [ m_current.m_id ].c_str ( ), m_current.m_text.c_str ( ) );
		consume ( );
	}
	else
	{
		throw "Expected : " + Lexer::TAGS [ p_type ] + " Found : " + Lexer::TAGS [ m_current.m_id ];
	}
}

void Parser::consume ( )
{
	m_current = m_lexer.next_token ( );
}
