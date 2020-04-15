#ifndef __seashell_exceptions_hpp__
#define __seashell_exceptions_hpp__

#include <string>
#include <exception>
#include <errno.h>

class SeashellException : public std::exception
{
public:
    explicit SeashellException(const char* message) :
        _message(message),
        _errno(errno)
    {}

    explicit SeashellException(const std::string& message) :
        _message(message),
        _errno(errno)
    {}

    virtual ~SeashellException()
    {}

private:
    std::string _message;
    error_t _errno;
};

#endif /* __seashell_exceptions_hpp__ */
