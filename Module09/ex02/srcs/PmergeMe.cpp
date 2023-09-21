#include <PmergeMe.hpp>

PmergeMe::PmergeMe( std::string data ) : _args(data) {
	std::cout << "\e[0;33mParameter Constructor called of PmergeMe \e[0m" << std::endl;
	std::cout << "------Original Data-----" << std::endl << data << std::endl;
	if (!checkDigit(_args))
	{
		std::cout << "Error: Wrong format argument" << std::endl;
		return ;
	}
	parseAndAddToLists();
	printLists();
	executer();
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _myList(copy.getStack()) {
	std::cout << "\e[0;33mCopy Constructor called of PmergeMe\e[0m" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& assign) {
	std::cout << "\e[0;33mAssignment Operator called of PmergeMe\e[0m" << std::endl;
	if (this != &assign) {
		this->_myList = assign.getStack();
		this->_args  = assign.getArgs();
	}
    return *this;
}

PmergeMe::~PmergeMe() {
	std::cout << "\e[0;33mDestructor called of PmergeMe\e[0m" << std::endl;
}

std::list<int> PmergeMe::getStack( void ) const {
	return this->_myList;
}

std::string	PmergeMe::getArgs( void ) const {
	return this->_args;
}

bool	PmergeMe::checkDigit(std::string str) {
	for (char c : str)
	{
		if (!std::isdigit(c) && !std::isspace(c) && c != '+')
		{
			std::cout << c << std::endl;
			return false;
		}
	}
	return true;
}

void	PmergeMe::parseAndAddToLists( void ) {
    std::istringstream iss(_args); // Create a string stream to tokenize the input
    std::string token;
	std::string	max = std::to_string(INT_MAX);
	int num;
    while (iss >> token) {
        if (token == "+")
            continue;
		if (token.size() >= max.size() && token.compare(max) > 0) {
			std::cout << "Value out of bounds: " << token << std::endl;
			exit(0);
		}
        if (std::istringstream(token) >> num) {
            _myList.push_back(num);
            _myDeck.push_back(num);
        }
    }
}

void	PmergeMe::printLists( void ) {
	std::cout << "---------List-----------" << std::endl;
	std::list<int>::iterator it = _myList.begin();
	for ( ; it != _myList.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "---------Deck-----------" << std::endl;
	 for (size_t i = 0; i < _myDeck.size(); ++i) {
        std::cout << _myDeck[i] << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::mergeInsert( void )
{
    for (std::list<int>::iterator it = _myList.begin(); it != _myList.end(); ) {
        if (_myList.size() == 1) {
            _sortedList.push_front(*it);
            return;
        }
        int currentElement = *it;
        ++it;
        if (it != _myList.end()) {
			if (*it > currentElement)
            	_listPair.push_back(std::make_pair(currentElement, *it));
			else
            	_listPair.push_back(std::make_pair(*it, currentElement));
			it++;
        }
		else
			_sortedList.push_back(currentElement);
    }
	printPairs();
}
void	PmergeMe::executer( void )  {
	mergeInsert();
}

void	PmergeMe::printPairs()
{
	 std::list<std::pair<int, int>>::iterator it;

    for (it = _listPair.begin(); it != _listPair.end(); ++it) {
        std::pair<int, int> pair = *it;
        std::cout << "Pair: (" << pair.first << ", " << pair.second << ")\n";
    }
}