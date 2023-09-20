#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <fstream>
# include <map>
# include <algorithm>
# include <stack>
# include <deque>

class	RPN {
	private:
		std::stack<int>	_myStack;
		std::string		_argm;
		char			_operation;
	public:
		RPN( std::string file );
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();
		std::stack<int>	getStack ( void ) const;
		char	checkOperation();
		bool	checkDigit(std::string str);
		bool	isOperation(char c);
		void	addNumberStack( void );
		void	executer( void );
		void	calculater(int first, int second);
};

#endif