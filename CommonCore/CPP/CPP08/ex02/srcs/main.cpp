#include <iostream>
#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "\n******* Subject Tests *******" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n******* const iterator *******" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n******* reverse iterator *******" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n******* const reverse iterator *******" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator ite = mstack.rend();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n******* Empty stack *******" << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Empty: " << mstack.empty() << std::endl;
	}

	std::cout << "\n******* Copy constructor *******" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int> mstack2(mstack);
		std::cout << "mstack2 size: " << mstack2.size() << std::endl;
		std::cout << "mstack2 top: " << mstack2.top() << std::endl;
	}

	std::cout << "\n******* Assignment operator *******" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int> mstack2;
		mstack2 = mstack;
		std::cout << "mstack2 size: " << mstack2.size() << std::endl;
		std::cout << "mstack2 top: " << mstack2.top() << std::endl;
	}

	std::cout << "\n******* Stack of strings *******" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n****** mutability *******" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		std::cout << "Before mutation: " << *it << std::endl;
		*it = 42;
		std::cout << "After mutation: " << *it << std::endl;
		//MutantStack<int>::const_iterator cit = mstack.begin();
		//*cit = 42; // This line should cause a compilation error
	}
}
