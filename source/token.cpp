#include "token.h"

Token::Token ( ) : m_text ( "" ), m_id ( -1 ) { }

Token::Token ( const std::string& p_text, int p_id ) : m_text ( p_text ), m_id ( p_id ) { }

Token::Token ( std::string&& p_text, int p_id ) : m_text ( p_text ), m_id ( p_id ) { }
