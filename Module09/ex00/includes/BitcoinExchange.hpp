#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <vector>
# include <fstream>
# include <map>
# include <algorithm>
# include <sstream>

class	BitcoinExchange {
	private:
		std::map<std::string, std::string> _bitMap;
		std::ifstream	_readFile;
		std::string		_filename;
	public:
		BitcoinExchange( std::string file );
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		//Class Methods
		// std::ifstream	getFileStream( void ) const;
		std::map<std::string, std::string>	getBitMap( void ) const;
		int	checkFile( void );
		void	readLines( void );
		bool	checkEmptyLine(std::string line) const;
		void	parseLine(const std::string& line, char delimiter);
		void	printMap( void );
		void	executeResults( void ) const;
		int		checkValue(std::string value);
		int		checkData(std::string data);
};

#endif