#ifndef __EXCEPTION__
#define __EXCEPTION__

#include <exception>
#include <iostream>

class MyException : public std::exception {
public:
    MyException(const std::string message) : _message(message) {}
    ~MyException() {}

    const char* what() const noexcept override;

private:
    std::string _message;
};

#endif // __EXCEPTION__