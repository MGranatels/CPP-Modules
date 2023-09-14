#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>
# include <string>

class Whatever {
	private:
	public:
		//Constructers and Destructers
		Whatever();
		Whatever(const Whatever& other);
		Whatever& operator=(const Whatever& other);
		Whatever(std::string name, int signGrade, int execGrade);
		~Whatever();

		template <typename T> void swap(T &x, T &y) {
			T tmp = x;
			x = y;
			y = tmp;
		}
		template <typename T> T const & min(T const &x, T const &y) {
			if (y <= x)
				return y;
			return x;
		}
		template <typename T> T const & max(T const &x, T const &y) {
			if (y >= x)
				return y;
			return x;
		}
};

#endif
