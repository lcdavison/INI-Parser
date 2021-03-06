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

	char input [ 128 ];

	while ( m_file.getline ( input, 128 ) )
	{
		//	Skip empty lines
		if ( m_file.gcount ( ) == 1 && (unsigned char) ( input [ 0 ] ) == 0 ) continue;
		
		ss << input << "\n";
	}

	return ss.str ( );
}

bool Reader::is_open ( )
{
	return m_file.is_open ( );
}
