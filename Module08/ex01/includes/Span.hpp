#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <ctime>


class	Span {
	private:
		std::vector<int> _arr;
		unsigned int _max;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		int		getMax() const;
		void	addListNumber(unsigned int amount);
		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();
		std::vector<int>	getVector() const;
		class LimitArrayException : public std::exception {
			public:
				virtual const char* what() const throw ();
		};
		class EmptyArrayException : public std::exception {
			public:
				virtual const char* what() const throw ();
		};
};

#endif