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
		std::map<std::string, std::string>	_bitMap;
		std::ifstream						_readFile;
		std::ifstream						_cvsFile;
		std::string							_filename;
	public:
		BitcoinExchange( std::string file );
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		//Class Methods
		// std::ifstream	getFileStream( void ) const;
		int		checkFile( void );
		bool	checkValue(std::string value);
		bool	checkEmptyLine(std::string line) const;
		bool	validateDate(std::string date);
		bool	checkDigit(std::vector<std::string> str);
		void	parseBitMap(const std::string& line, char delimiter);
		void	printMap( void );
		void	executeResults( void );
		std::vector<std::string>			readLines( void );
		std::vector<std::string>			splitData(const std::string& line, char delimiter);
		std::map<std::string, std::string>	getBitMap( void ) const;

};

#endif