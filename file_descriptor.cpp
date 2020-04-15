#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "file_descriptor.hpp"


FileDescriptor::FileDescriptor() :
    _fd(INVALID_FILE_DESCRIPTOR)
{}

FileDescriptor::FileDescriptor(int fd) :
    _fd(fd)
{
    if (_fd == INVALID_FILE_DESCRIPTOR)
    {
        throw SeashellException("Invalid file descriptor");
    }
}

FileDescriptor::FileDescriptor(std::string_view path, int flags) :
    FileDescriptor(::open(path.data(), flags))
{}

FileDescriptor::~FileDescriptor()
{
    try
    {
        if (_fd != INVALID_FILE_DESCRIPTOR)
        {
            ::close(_fd);
        }
    }
    catch (...)
    {}
}

FileDescriptor::FileDescriptor(FileDescriptor&& other) noexcept :
    _fd(other._fd)
{
    other._fd = INVALID_FILE_DESCRIPTOR;
}

FileDescriptor& FileDescriptor::operator=(FileDescriptor&& other) noexcept
{
    if (this != &other)
    {
        _fd = other._fd;
        other._fd = INVALID_FILE_DESCRIPTOR;
    }

    return *this;
}

void FileDescriptor::dup(const FileDescriptor& oldfd)
{
    if (*this != oldfd)
        dup2(oldfd._fd, _fd);
}

FileDescriptor& FileDescriptor::in()
{
    static FileDescriptor _stdin(STDIN_FILENO);
    return _stdin;
}

FileDescriptor& FileDescriptor::out()
{
    static FileDescriptor _stdout(STDOUT_FILENO);
    return _stdout;
}

FileDescriptor& FileDescriptor::err()
{
    static FileDescriptor _stderr(STDERR_FILENO);
    return _stderr;
}
