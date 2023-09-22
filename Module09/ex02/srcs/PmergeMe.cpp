#include <PmergeMe.hpp>

PmergeMe::PmergeMe( std::string data ) : _args(data) {
	std::cout << "\e[0;33mParameter Constructor called of PmergeMe \e[0m" << std::endl;
	//std::cout << "------Original Data-----" << std::endl << data << std::endl;
	if (!checkDigit(_args)) {
		std::cout << "Error: Wrong format argument" << std::endl;
		return ;
	}
	parseAndAddToLists();
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
            _firstDeck.push_back(num);
        }
    }
	_size = _myList.size();
}

void	PmergeMe::printLists( void ) {
	std::cout << "---------List-----------" << std::endl;
	std::list<int>::iterator it = _sortedList.begin();
	for ( ; it != _sortedList.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "---------Deck 1-----------" << std::endl;
	 for (size_t i = 0; i < _firstDeck.size(); ++i) {
        std::cout << _firstDeck[i] << " ";
    }
	/*std::cout << std::endl;
	std::cout << "---------Deck 2-----------" << std::endl;
	 for (size_t i = 0; i < _secondDeck.size(); ++i) {
        std::cout << _secondDeck[i] << " ";
    }
	std::cout << std::endl;*/
}

void PmergeMe::insertionList()
{
    for (std::list<std::pair<int, int>>::iterator it = _listPair.begin(); it != _listPair.end(); ++it)
    {
        if (_sortedList.empty()) {
            _sortedList.push_back(it->first);
            _sortedList.push_back(it->second);
        }
        else {
            std::list<int>::iterator it2 = _sortedList.begin();
            while (it2 != _sortedList.end() && *it2 < it->first) {
                ++it2;
            }
            _sortedList.insert(it2, it->first);

            it2 = _sortedList.begin();
            while (it2 != _sortedList.end() && *it2 < it->second) {
                ++it2;
            }
            _sortedList.insert(it2, it->second);
        }
    }
    //printLists();
}

void PmergeMe::mergeInsertList( void )
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
	insertionList();
}

void PmergeMe::insertionDeque( void )
{
	if (_secondDeck.size() % 2 != 0) {
		_firstDeck.push_front(_secondDeck.back());
		_secondDeck.pop_back();
	}
	else {
		_firstDeck.push_back(_secondDeck.back());
		_firstDeck.push_front(_secondDeck.front());
		_secondDeck.pop_front();
		_secondDeck.pop_back();
	}
	while (_secondDeck.size() > 0) {
		std::deque<int>::iterator it = _firstDeck.begin();
		while (it != _firstDeck.end() && *it < _secondDeck.front()) {
			++it;
		}
		_firstDeck.emplace(it, _secondDeck.front());
		//_firstDeck.insert(it2, _secondDeck.front());
		_secondDeck.pop_front();

		while (it != _firstDeck.end() && *it < _secondDeck.back()) {
			++it;
		}
		_firstDeck.emplace(it, _secondDeck.back());
		//_firstDeck.insert(it, _secondDeck.back());
		_secondDeck.pop_back();
	}
}

/*
myDeque.push_back(4);
myDeque.push_front(0);
myDeque.pop_back();
myDeque.pop_front();
*/

void PmergeMe::mergeInsertDeque( void )
{
	std::deque<int>::iterator it = _firstDeck.begin();
	if (_firstDeck.size() == 1) {
		_secondDeck.push_front(*it);
		return;
	}
 	for (; it != _firstDeck.end(); ) {
		int currentElement = *it;
		++it;
		if (it != _firstDeck.end()) {
			if (*it > currentElement) {
				_secondDeck.push_back(*it);
				_secondDeck.push_front(currentElement);
			}
			else {
				_secondDeck.push_back(currentElement);
				_secondDeck.push_front(*it);
			}
			it++;
		}
		else
			_secondDeck.push_back(currentElement);
	}
	_firstDeck.clear();
	insertionDeque();
}

void	PmergeMe::executer( void )  {
	long double deckTime;
	long double listTime;

	std::cout << "Before: " << printer(_myList) << std::endl;
	std::cout << "After: " << printer(_firstDeck) << std::endl;
	std::clock_t start = std::clock();
	mergeInsertList();
	listTime = (double)((std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
	start = std::clock();
	mergeInsertDeque();
	deckTime = (double)((std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
	//printLists();
	std::cout << "Time to process a range of " << _size << " elements with std::deck: " << deckTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::list: " << listTime << " ms" << std::endl;
}

// Function that returns the timestamp()

void	PmergeMe::printPairs()
{
	 std::list<std::pair<int, int>>::iterator it;

    for (it = _listPair.begin(); it != _listPair.end(); ++it) {
        std::pair<int, int> pair = *it;
        std::cout << "Pair: (" << pair.first << ", " << pair.second << ")\n";
    }
}