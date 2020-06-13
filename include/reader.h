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

		std::string read ( );

		bool is_open ( );

	private:

		std::string 	m_filename;
		std::ifstream 	m_file;
};
#endif
