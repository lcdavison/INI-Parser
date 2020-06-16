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

#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <sstream>

class Reader 
{
	public:

		Reader ( std::string&& );
		~Reader ( );

		/*
		 *	Reads the content of a file into a string object.
		 * */
		std::string read ( );

		/*
		 *	Determines whether the file is currently open.
		 * */
		bool is_open ( );

	private:

		std::string 	m_filename;	//	The name of the file
		std::ifstream 	m_file;		//	The input file stream
};
#endif
