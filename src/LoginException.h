#pragma once
#include <exception>
#include <string>
class LoginException : public std::exception
{
        std::string s; // Exception text
        LoginException(std::string ss) : s(ss) {} // Constructor
        ~LoginException() throw () {} // Destructor
        const char* what() const throw() { return s.c_str(); } // Output error message
};

