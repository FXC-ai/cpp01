#include <iostream>
#include <fstream>
#include <sstream>

std::string readFileIntoString(const std::string& path) {
    std::ifstream input_file(path);
    if (!input_file.is_open()) 
	{
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

int main()
{
    std::string filename("input.txt");
    std::string file_contents;

    file_contents = readFileIntoString(filename);

	std::size_t found(0);
	std::size_t i(0);

	while (found != std::string::npos)
	{
		found = file_contents.find("Rieux", i);
		std::cout << found << std::endl;
		//file_contents.erase(0, 5);
		i = found + 1;
	}


    //std::cout << found << std::endl;



    std::cout << file_contents << std::endl;

    exit(EXIT_SUCCESS);
}
