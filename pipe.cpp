#include <array>

#include <unistd.h>

#include "pipe.hpp"

Pipe::Pipe()
{
    std::array<int, FD_COUNT> pipe_ends = { 0 };
    if (LIBC_SUCCESS != ::pipe(pipe_ends.data()))
    {
        throw SeashellException("Could not create pipe");
    }

    _out = FileDescriptor(pipe_ends[FD_READ]);
    _in = FileDescriptor(pipe_ends[FD_WRITE]);
}
