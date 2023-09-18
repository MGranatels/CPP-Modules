#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class	Array {
	private:
		T *_arr;
		unsigned int _size;
	
	public:
		Array<T>() : _size(0)
		{
			std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
			_arr = new T[0];
		}
		Array<T>(unsigned int n) : _size(n)
		{
			std::cout << "\e[0;33mConstructor called of Array\e[0m" << std::endl;
			_arr = new T[n];
		}
		Array<T>(const Array<T> &copy) : _size(copy._size)
		{
			std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
			_arr = new T[copy._size];
			for (unsigned int i = 0; i < copy._size; i++)
				_arr[i] = copy._arr[i];
		}
		Array<T> & operator=(const Array<T> &assign)
		{
			std::cout << "\e[0;33mAssignment Operator called of Array\e[0m" << std::endl;
			if (this != &assign)
			{
				delete [] _arr;
				_arr = new T[assign._size];
				for (unsigned int i = 0; i < assign._size; i++)
					_arr[i] = assign._arr[i];
			}
			return *this;
		}
		~Array<T>()
		{
			std::cout << "\e[0;33mDestructer called of Array\e[0m" << std::endl;
			delete [] _arr;
		}
		T & operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return _arr[index];
		}
		unsigned int size(void) const
		{
			return _size;
		}
		void	printArray(void)
		{
			for (unsigned int i = 0; i < _size; i++)
				std::cout << _arr[i] << std::endl;
		}
};

#endif