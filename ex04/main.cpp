#include <iostream>
#include <fstream>
#include <sstream>

int readFileIntoString(const std::string& filename, std::string& file_contents) 
{
    std::ifstream in_file(filename);
    if (!in_file.is_open()) 
	{
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return 1;
    }
    file_contents = std::string((std::istreambuf_iterator<char>(in_file)), std::istreambuf_iterator<char>());
    in_file.close();
    return 0;
}

int readStringIntoFile(const std::string& filename_r, std::string& file_contents)
{
    std::ofstream out_file(filename_r);
    if (!out_file.is_open()) 
	{
        std::cerr << "Could not open the file - '" << filename_r << "'" << std::endl;
        return 1;
    }
    out_file << file_contents;
    out_file.close();
    return 0;
}

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        std::cerr << "Invalid number of arguments." << std::endl;
        return (0);
    }

    const std::string   filename(argv[1]);
    const std::string   s1(argv[2]);
    const std::string   s2(argv[3]);
    int                 size_s1(s1.length());
    std::string         file_contents;
	std::size_t         found(0);
	std::size_t         i(0);
    const std::string   filename_r(filename + ".replace");

    if (readFileIntoString(filename, file_contents) == 1)
        return (0);

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

    if (readStringIntoFile(filename_r, file_contents) == 1)
        return (0);

    return (0);
}
