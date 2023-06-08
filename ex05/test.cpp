#include <map>
#include <string>
#include <iostream>

int main ()
{
	std::map<std::string, int> listest;

	listest["a"] = 2;
	listest["b"] = 4;

	std::cout << listest["FX"] << std::endl;

	std::map<std::string, int>::iterator it;


	for (it = listest.begin(); it != listest.end(); it++)
	{
		std::cout << it->first << std::endl;

	}


	return (0);
}

// #include<deque>
// #include <iostream>
// using namespace std;

// int main()
// {
//     deque<int> d(5,6);        //Une deque de 5 éléments valant 6
//     deque<int>::iterator it;  //Un itérateur sur une deque d'entiers

//     //Et on itère sur la deque
//     for(it = d.begin(); it!=d.end(); ++it)
//     {
//         cout << *it << endl;    //On accède à l'élément pointé via l'étoile
//     }
//     return 0;
// }