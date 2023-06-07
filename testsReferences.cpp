#include <string>
#include <iostream>

void	byRef(std::string &str)
{
	std::cout << str << std::endl;

}

std::string &getREF(std::string str)
{
	return str;
}

int main ()
{	
	std::string	chain = new std::string("Bonjour");

	std::string	&stringREF = getREF(chain);

	byRef(stringREF);

	return 0;
}


/**/