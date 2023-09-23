#include <RPN.hpp>

RPN::RPN( std::string polish ) : _argm(polish) {
	std::cout << "\e[0;33mParameter Constructor called of RPN \e[0m" << std::endl;
	if (!checkDigit(_argm))
	{
		std::cout << "Error: Wrong format argument" << std::endl;
		return ;
	}
	executer();
}

RPN::RPN(const RPN& copy) : _myStack(copy.getStack()) {
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}

RPN& RPN::operator=(const RPN& assign) {
	std::cout << "\e[0;33mAssignment Operator called of RPN\e[0m" << std::endl;
	if (this != &assign) {
		this->_myStack = assign.getStack();
	}
    return *this;
}

RPN::~RPN() {
	std::cout << "\e[0;33mDestructor called of RPN\e[0m" << std::endl;
}

std::stack<int>	RPN::getStack ( void ) const {
	return this->_myStack;
}

char	RPN::checkOperation()
{
	std::string operations[4] = {"+","-","*","/"};
	size_t		cls;
	size_t		res = _argm.size() + 1;

	for (int i = 0; i < 4; i++) {
		cls = _argm.find(operations[i]);
		res = (res > cls) ? cls : res;
	}
	if (res == _argm.size() + 1)
		return ('\0');
	return (_argm[res]);
}

bool	RPN::isOperation(char c)
{
	return (c > 41 && c < 48);
}

bool	RPN::checkDigit(std::string str) {
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && !isOperation(str[i]) && !std::isspace(str[i]))
			return false;
		if (str[i] == 46 || str[i] == 44)
			return false;
	}
	return true;
}

void	RPN::addNumberStack( void )
{
	unsigned int	i = 0;
	
	while (i < _argm.size())
	{
		if (isOperation(_argm[i]))
			break ;
		if (std::isdigit(_argm[i]))
			_myStack.push(static_cast<int>(_argm[i] - 48));
		i++;
	}
	_argm.erase(0, i + 1);
}

void	RPN::calculater(int first, int second)
{
	switch (_operation) {
		case '+':
			_myStack.push(second + first);
			break;
		case '-':
			_myStack.push(second - first);
			break;
		case '*':
			_myStack.push(second * first);
			break;
		case '/':
			_myStack.push(second / first);
			break;
	}
}

void	RPN::executer( void ) 
{
	int	first;
	int	second;

	while (!_argm.empty())
	{
		_operation = checkOperation();
		addNumberStack();
		if (!_operation || _myStack.empty())
			break;
		first = _myStack.top();
		_myStack.pop();
		if (_myStack.empty())
			break ;
		second = _myStack.top();
		_myStack.pop();
		calculater(first, second);
	}
	if (!_myStack.empty() && _myStack.size() == 1)
		std::cout << "Result: " << _myStack.top() << std::endl;
	else
		std::cout << "Error: Incorrect Polish Expression" << std::endl;
}