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
	if (!validateDate(date) || !checkValue(value, line))
		_bitMap.erase(date);
}

bool BitcoinExchange::checkEmptyLine(std::string line) const {
	return std::all_of(line.begin(), line.end(), ::isspace);
}


std::vector<std::string> BitcoinExchange::splitData(const std::string& line, char delimiter) {
    std::vector<std::string> splitLine;
    std::string tmp;
    std::istringstream iss(line);

    while (std::getline(iss, tmp, delimiter)) {
        // Remove leading and trailing whitespaces from 'tmp'
        tmp.erase(tmp.begin(), std::find_if(tmp.begin(), tmp.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        tmp.erase(std::find_if(tmp.rbegin(), tmp.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), tmp.end());

        splitLine.push_back(tmp);
    }
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

bool	BitcoinExchange::checkValue(std::string value, std::string line) {
	std::vector<std::string>	splitValue = splitData(value, '.');
	float nb = std::stof(value);
	if (value.empty())
	{
		std::cout << line << "\e[0;31m => Error: Missing value argument!\e[0m" << std::endl;	
		return false;
	}
	if (!checkDigit(splitValue))
	{
		std::cout << line << "\e[0;31m => Error: Value can only contain digits!\e[0m" << std::endl;
		return false;
	}
	if (nb > 1000 || nb < 0)
	{
		std::cout << line << "\e[0;31m => Error: Value out of bonds!\e[0m" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::validateTxtLines(std::string line, std::vector<std::string> splitTxt)
{
	if (line.find('|', 0) == std::string::npos)
	{
		std::cout << line << "\e[0;31m => Error: No separation defined for value and Date\e[0m" << std::endl;
		return false;
	}
	if (!validateDate(splitTxt[0]))
	{
		std::cout << line << "\e[0;31m => Error: Incorrect Data Format\e[0m" << std::endl;
		return false;
	}
	if (!checkValue(splitTxt[1], line))
		return false;
	if (splitTxt.size() != 2)
		return false;
	return true;
}

void BitcoinExchange::findClosestDate(std::vector<std::string> splitTxt) {
    std::string targetDate = splitTxt[0];
    std::map<std::string, std::string>::const_iterator closestDateIt = _bitMap.begin();
    float minDifference = std::numeric_limits<float>::max();

    for (std::map<std::string, std::string>::const_iterator it = _bitMap.begin(); it != _bitMap.end(); ++it) {
        // Calculate the absolute difference between targetDate and the current date
        float a = std::stof(it->first);
        float b = std::stof(targetDate);
        float difference = std::abs(a - b);
        if (difference < minDifference) {
            closestDateIt = it;
            minDifference = difference;
        }
    }
    float closestValue = std::stof(closestDateIt->second);
	std::cout << splitTxt[0] << " => " << splitTxt[1] << " = " << std::stof(splitTxt[1]) * closestValue << std::endl;
}

bool	BitcoinExchange::findDate(std::vector<std::string> splitTxt)
{
	for (std::map<std::string, std::string>::const_iterator it = _bitMap.begin(); it != _bitMap.end(); ++it) 
	{
		if (it->first == splitTxt[0])
		{
			float a = std::stof(it->second);
			float b = std::stof( splitTxt[1]);
			std::cout << splitTxt[0] << " => " << splitTxt[1] << " = " << a * b << std::endl;
			return true;
		}
	}
	return false;
}

void	BitcoinExchange::executeResults( void ) {
	std::vector <std::string>	splitTxt;
	std::string			line;

	std::getline(_readFile, line);
	while (std::getline(_readFile, line))
	{  
		splitTxt = splitData(line, '|');
		if (!validateTxtLines(line, splitTxt)) {
			continue;
		}
		else
			if (!findDate(splitTxt))
				findClosestDate(splitTxt);
		splitTxt.clear();
	}
}