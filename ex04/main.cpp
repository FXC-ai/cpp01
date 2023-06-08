#include <iostream>
#include <fstream>
#include <sstream>

std::string readFileIntoString(const std::string& path) 
{
    std::ifstream in_file(path);
    if (!in_file.is_open()) 
	{
        std::cerr << "Could not open the file - '" << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(in_file)), std::istreambuf_iterator<char>());
}

void        readStringIntoFile(const std::string& path, std::string text)
{
    std::string filename_r(path);

    std::ofstream out_file(filename_r);
    if (!out_file.is_open()) 
	{
        std::cerr << "Could not open the file - '" << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    out_file << text;
    out_file.close();
}

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        std::cerr << "Invalid number of arguments." << std::endl;
        return 0;
    }

    const std::string   filename(argv[1]);
    const std::string   s1(argv[2]);
    const std::string   s2(argv[3]);
    int                 size_s1(s1.length());
    std::string         file_contents;
	std::size_t         found(0);
	std::size_t         i(0);
    const std::string   filename_r(filename + ".replace");

    file_contents = readFileIntoString(filename);

	while (found != std::string::npos)
	{
		found = file_contents.find(s1, i);
        if (found != std::string::npos)
        {
		    file_contents.erase(found, size_s1);
            file_contents.insert(found, s2);
		    i = found + 1;
        }
	}

    readStringIntoFile(filename_r, file_contents);
 
    exit(EXIT_SUCCESS);
}
