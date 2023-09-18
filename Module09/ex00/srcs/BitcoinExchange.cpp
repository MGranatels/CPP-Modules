#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange( std::string file ) : _filename(file) {
	std::cout << "\e[0;33mParameter Constructor called of BitcoinExchange \e[0m" << std::endl;
	if (!checkFile())
		return ;
	executeResults();
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
		std::cerr << "Failed to open txt the file." << std::endl;
		return 0;
	}
	_cvsFile.open("data.csv");
	if (!_cvsFile.is_open()) {
		std::cerr << "Failed to open cvs file." << std::endl;
		return 0;
	}
	std::string line;
	while (std::getline(_cvsFile, line)) 
	{
		if (checkEmptyLine(line))
		{
			std::cout << "Line Skipped !" << std::endl;
			continue;
		}
		parseBitMap(line, ',');
    }
	return 1;
}

void	BitcoinExchange::parseBitMap(const std::string& line, char delimiter) {
    std::istringstream iss(line);
    std::string date, value;

  	if (line.find(delimiter, 0) == std::string::npos)
		_bitMap[line] = "";
    else if (std::getline(iss, date, delimiter) && std::getline(iss, value)) {
        _bitMap[date] = value;
    }
	if (!validateDate(date) || !checkValue(value))
		_bitMap.erase(date);
}

bool BitcoinExchange::checkEmptyLine(std::string line) const {
	return std::all_of(line.begin(), line.end(), ::isspace);
}


std::vector<std::string>	BitcoinExchange::splitData(const std::string& line, char delimiter) {
	std::vector<std::string>	splitLine;
	std::string					tmp;
	std::istringstream			iss(line);

	while (std::getline(iss, tmp, delimiter))
		splitLine.push_back(tmp);
	return splitLine;
}


void BitcoinExchange::printMap( void ) {
    for (std::map<std::string, std::string>::const_iterator it = _bitMap.begin(); it != _bitMap.end(); ++it) {
        std::cout << it->first << "," << it->second << std::endl;
    }
}

bool	BitcoinExchange::checkDigit(std::vector<std::string> str) {
	for (unsigned int i = 0; i < str.size(); i++)
		for (char c : str[i])
			if (!std::isdigit(c))
				return false;
	return true;
}

bool	BitcoinExchange::validateDate( std::string date ) {
	std::vector<std::string>	splitDate;

	splitDate = splitData(date, '-');
	if (splitDate.size() != 3 || !checkDigit(splitDate))
		return false;
	if (splitDate[1].size() != 2 || splitDate[2].size() != 2 || splitDate[0].size() != 4)
		return false;
	int month = std::stoi(splitDate[1]);
	int day = std::stoi(splitDate[2]);
	if (day > 31 || month > 12)
		return false;
	return true;
}

bool	BitcoinExchange::checkValue(std::string value) {
	std::vector<std::string>	splitValue = splitData(value, '.');
	float nb = std::stof(value);
	if (value.empty())
		return false;
	if (!checkDigit(splitValue))
		return false;
	if (nb > 1000 || nb < 0)
		return false;
	return true;
}

std::vector<std::string>	BitcoinExchange::readLines() {
	std::string line;
	std::vector <std::string>	splitTxt;

  	while (std::getline(_readFile, line)) 
	{
		if (line.find("date"))
			continue;
		if (checkEmptyLine(line))
			continue ;
		if (line.find('|', 0) == std::string::npos) {
			std::cerr << "\e[0;31mInvalid value format or out of bonds in TXT: \e[0m" << line << std::endl;
			continue;
		}
		splitTxt = splitData(line, '|');
		if (!checkDigit(splitTxt) || !validateDate(splitTxt[0]) || !checkValue(splitTxt[1])) {
			std::cerr << "\e[0;31mInvalid value format or out of bonds in TXT: \e[0m" << line << std::endl;
			continue;
		}
    }
	return splitTxt;
}

 void	BitcoinExchange::executeResults( void ) {
	std::vector <std::string>	splitTxt;
	int i = 0;
	while (i < 2 )
	{   
		splitTxt = readLines();
		if (splitTxt.empty())
			break;
		std::map<std::string, std::string>::iterator it = _bitMap.find(splitTxt[0]);
		if (it != _bitMap.end())
			std::cout << "No match Found for: " <<   splitTxt[0] << " | " << splitTxt[1] << std::endl;
		else
		{
			std::cout << "Value of txt: " << splitTxt[1] << std::endl;
			std::cout << "Value of rate in csv: " << it->second << std::endl;
			//float a = std::stof(splitTxt[1]);
			//float b = std::stof(it->second);

			//std::cout << splitTxt[0] << "=>" << splitTxt[1]  << "= " << a * b << std::endl;
		}

	}
}