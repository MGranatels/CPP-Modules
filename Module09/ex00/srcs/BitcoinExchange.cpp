#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange( std::string file ) : _filename(file) {
	std::cout << "\e[0;33mParameter Constructor called of BitcoinExchange \e[0m" << std::endl;
	if (!checkFile())
		return ;
	readLines();
	// executeResults();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _bitMap(copy.getBitMap()) {
	std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assign) {
	std::cout << "\e[0;33mAssignment Operator called of BitcoinExchange\e[0m" << std::endl;
	if (this != &assign) {
		this->_bitMap = assign.getBitMap();
	}
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "\e[0;33mDestructor called of BitcoinExchange\e[0m" << std::endl;
	if (_readFile.is_open())
		_readFile.close();
}

std::map<std::string, std::string>	BitcoinExchange::getBitMap( void ) const {
	return this->_bitMap;
}

int	BitcoinExchange::checkFile( void ) {
	if (_filename.size() <= 4 || _filename.compare(_filename.length() - 4, 4, ".txt") != 0 )  {
		std::cerr << "Not a valid .txt file" << std::endl;
		return 0;
	}
	_readFile.open(_filename);
	if (!_readFile.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 0;
	}
	return 1;
}

bool BitcoinExchange::checkEmptyLine(std::string line) const {
	return std::all_of(line.begin(), line.end(), ::isspace);
}

void	BitcoinExchange::parseLine(const std::string& line, char delimiter) {
    std::istringstream iss(line);
    std::string date, value;
	static	int	i = 0;

  	if (line.find(delimiter, 0) == std::string::npos)
		_bitMap[std::to_string(i) + ". " + line] = "";
    else if (std::getline(iss, date, delimiter) && std::getline(iss, value)) {
        _bitMap[std::to_string(i) + ". " + date] = value;
    }
	i++;
}

void	BitcoinExchange::readLines() {
	std::string line;

  	while (std::getline(_readFile, line)) 
	{
		if (checkEmptyLine(line))
		{
			std::cout << "Line Skipped !" << std::endl;
			continue;
		}
		parseLine(line, '|');
    }
	printMap();
}

void BitcoinExchange::printMap( void ) {
    for (std::map<std::string, std::string>::const_iterator it = _bitMap.begin(); it != _bitMap.end(); ++it) {
        std::cout << "Data: " << it->first << ", Value: " << it->second << std::endl;
    }
}

// void	BitcoinExchange::executeResults( void ) const {
// 	 for (std::map<std::string, std::string>::const_iterator it = _bitMap.begin(); it != _bitMap.end(); ++it) {
// 		if (!checkData(it->first))
// 			continue;
// 		if (!checkValue(it->second))
// 			continue;
// 		apply()
// 	 }
// }