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

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

struct Token 
{
	Token ( );
	Token ( const std::string&, int );
	Token ( std::string&&, int );

	std::string 	m_text;		//	String representing token
	int 		m_id;		//	Id representing token type
};
#endif
