#include <MutantStack.hpp>

int	main ()
{
	MutantStack<int> newStack;

	newStack.push(10);
	newStack.push(7);
	std::cout << "Top Element: " << newStack.top() << std::endl;
	newStack.pop();
	std::cout << "New Top Element: " << newStack.top() << std::endl;
	newStack.pop();
	if (newStack.empty())
		std::cout << "This will evaluate to true because stack is empty now :)" << std::endl;
	for (int i = 0; i < 10; i++)
		newStack.push(i);
	MutantStack<int>::iterator itBegin = newStack.begin();
	MutantStack<int>::iterator itEnd = newStack.end();
	int	i = 1;
	while (itBegin != itEnd)
	{
		std::cout << "Stack Value for newStack in " << i << " postion: " << *itBegin << std::endl;
		itBegin++;
		i++;
	}
	std::cout << std::endl;
	MutantStack<int> wtfStack(newStack);
	MutantStack<int>::iterator itBegin2 = wtfStack.begin();
	MutantStack<int>::iterator itEnd2 = wtfStack.end();
	i = 1;
	while (itBegin2 != itEnd2)
	{
		std::cout << "Stack Value for wtfStack in " << i << " postion: " << *itBegin2 << std::endl;
		itBegin2++;
		i++;
	}
}