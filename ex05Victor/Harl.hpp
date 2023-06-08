#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>


class Harl
{

    public:
        Harl();
        ~Harl();
        void complain(const std::string &level);
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::map<std::string, void(Harl::*)(void)> complaintFunctions;
};



#endif