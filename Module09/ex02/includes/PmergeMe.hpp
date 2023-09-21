#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <deque>
# include <list>
# include <limits.h>
# include <cstdlib>
# include <ctime>
# include <string>

class	PmergeMe {
	private:
		std::list<int>	_myList;
		std::list<int>	_sortedList;
		std::deque<int>	_myDeck;
		std::string		_args;
		std::list<std::pair<int,int> > _listPair;
		std::deque<std::pair<int,int> > _dequePair;

	public:
		PmergeMe( std::string data );
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		std::list<int>	getStack( void ) const;
		std::string		getArgs( void ) const;
		bool			checkDigit(std::string str);
		void			parseAndAddToLists( void );
		void			executer( void );
		void			parseNb( void );
		void			printLists( void );
		void			mergeInsert( void );
		void			printPairs( void );
};		

#endif