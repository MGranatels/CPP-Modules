#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>

class	MutantStack : public std::stack<T> {
	public:
		MutantStack( void )  : std::stack<T>() {
			std::cout << "\e[0;33mDefault Constructor called of MutantStack \e[0m" << std::endl;
		} ;
		MutantStack(const MutantStack& copy): std::stack<T>(copy) {
			std::cout << "\e[0;33mCopy Constructor called of MutantStack \e[0m" << std::endl;
		};
		MutantStack& operator=(const MutantStack& other){
			std::cout << "\e[0;33mAssignment Operator Constructor called of MutantStack \e[0m" << std::endl;
			if (this == &other)
        		return *this; // Handle self-assignment
			static_cast<std::stack<T>&>(*this) = static_cast<const std::stack<T>&>(other);
			return *this;
    	}
		~MutantStack() {
			std::cout << "\e[0;33mDestructor called of MutantStack \e[0m" << std::endl;
		};
		typedef typename std::deque<T>::iterator iterator;
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif