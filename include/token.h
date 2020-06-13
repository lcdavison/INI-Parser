#ifndef TOKEN_H
#define TOKEN_H

#include <string>

struct Token 
{
	Token ( );
	Token ( const std::string&, int );
	Token ( std::string&&, int );

	std::string 	m_text;
	int 		m_id;
};
#endif
