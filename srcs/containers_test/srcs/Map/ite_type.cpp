#include "common.hpp"

int		main(void)
{
	TESTED_NAMESPACE::Map<char, int>::iterator it;
	TESTED_NAMESPACE::Map<char, float>::const_iterator ite;

	std::cout << (it != ite) << std::endl;
	return (0);
}
