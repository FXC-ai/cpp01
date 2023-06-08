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
        std::map<std::string, void(Harl::*)(void)> map_fct;

};

Harl::Harl ()
{
    this->map_fct["DEBUG"] = &Harl::debug;
    this->map_fct["INFO"] = &Harl::info;
    this->map_fct["WARNING"] = &Harl::warning;
    this->map_fct["ERROR"] = &Harl::error;
}

Harl::~Harl (){}

void    Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn t put enough bacon in my burger ! If you did, I wouldn t be asking for more !" << std::endl;

}

void    Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;

}

void    Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}

void    Harl::complain(std::string level)
{
    if (level == "DEBUG" || level == "INFO" || level == "ERROR" || level == "WARNING")
    {
        (this->*map_fct[level])();
    }
}

int main()
{

    Harl obj_harl;

    obj_harl.complain("DEBUG");
    obj_harl.complain("INFO");
    obj_harl.complain("ERROR");
    obj_harl.complain("WARNING");
    obj_harl.complain("nimportequoi");

    return (0);
}
