#include "reader.h"

#include <iostream>

Reader::Reader ( std::string&& p_filename ) : m_filename ( p_filename )
{
	m_file.open ( m_filename );
}

Reader::~Reader ( )
{
	m_file.close ( );
}

std::string Reader::read ( )
{
	std::stringstream ss;

	char input [ 32 ];

	while ( m_file.getline ( input, 32 ) )
	{
		ss << input;
	}

	return ss.str ( );
}

bool Reader::is_open ( )
{
	return m_file.is_open ( );
}
