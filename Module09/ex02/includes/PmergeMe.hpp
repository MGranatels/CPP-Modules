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
# include <chrono>
# include <iomanip>

class	PmergeMe {
	private:
		int				_size;
		std::list<int>	_myList;
		std::list<int>	_sortedList;
		std::deque<int>	_secondDeck;
		std::deque<int>	_firstDeck;
		std::string		_args;
		std::list<std::pair<int,int> > _listPair;

	public:
		PmergeMe( std::string data );
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		std::list<int>	getStack( void ) const;
		std::string		getArgs( void ) const;
		bool			checkDigit(std::string str);
		void			insertionList( void );
		void			insertionDeque( void );
		void			parseAndAddToLists( void );
		void			executer( void );
		void			parseNb( void );
		void			printLists( void );
		void			mergeInsertList( void );
		void			mergeInsertDeque( void );
		void			printPairs( void );
		template <typename T>
		static std::string	printer(T const &c)
		{
			std::stringstream ss;
			for (typename T::const_iterator it = c.begin(); it != c.end(); it++)
				ss << *it << " ";
			return ss.str();
		}
};

#endif