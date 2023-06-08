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
        //std::map<std::string, void(Harl::*)(void)> map_fct;

};

Harl::Harl (){}
// {
//     this->map_fct["debug"] = 



// }

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

    std::map<std::string, void(Harl::*)(void)> map_fct;

    map_fct["debug"] = &Harl::debug;
    map_fct["info"] = &Harl::info;
    map_fct["warning"] = &Harl::warning;
    map_fct["error"] = &Harl::error;

    (this->*map_fct[level])();

    // (this->(*(map_fct[level])))();
    //std::cout << test[level] << std::endl;

}

int main()
{

    Harl obj_harl;

    obj_harl.complain("debug");
    obj_harl.complain("info");
    obj_harl.complain("error");
    obj_harl.complain("warning");

    return (0);
}
