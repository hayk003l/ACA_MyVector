#include "Exception.hpp"


const char* MyException::what() const noexcept {
        return _message.c_str();
    }