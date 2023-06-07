#include <iostream>
#include <fstream>


int main()
{





	
	std::string		text;
	std::ifstream	infile("filename");

	infile >> text;
	std::cout << text;


	infile.close();


	

	return (0);
}