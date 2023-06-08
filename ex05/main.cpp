#include <iostream>
#include <map>

class Harl
{
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
    
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

};

Harl::Harl (){}
Harl::~Harl (){}

void    Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
}

void    Harl::complain(std::string level)
{
    (void) level;
    std::map<std::string, void(Harl::*)(void)> map_fct;

    map_fct["debug"] = &Harl::debug;
    map_fct["info"] = &Harl::info;
    map_fct["warning"] = &Harl::warning;
    map_fct["error"] = &Harl::error;


    // void(Harl::*ptr)(void);
    // ptr = &Harl::error;

    // this->((*ptr)());

    //this->debug();
    //(this->(*(map_fct[level])))();
    //std::cout << test[level] << std::endl;

}

int main()
{

    Harl obj_harl;

    obj_harl.complain("debug");

    return (0);
}
