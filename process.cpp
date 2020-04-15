#include <sys/types.h>
#include <sys/wait.h>

#include "process.hpp"

Process::Process(
    char* prog,
    char** arguments,
    FileDescriptor& in,
    FileDescriptor& out,
    FileDescriptor& err
):
    _process_id(fork())
{
    switch (_process_id)
    {
    case INVALID_PROCESS_ID:
        throw SeashellException("Could not create process");

    case CHILD_PROCESS_ID:
        in.dup(FileDescriptor::in());
        out.dup(FileDescriptor::out());
        err .dup(FileDescriptor::err());

        ::execvp(prog, arguments);

    default:
        break;
    }
}

Process::~Process()
{
    try
    {
        wait();
    }
    catch (...)
    {}
}

int Process::wait()
{
    int status;
    if (_process_id != ::waitpid(_process_id, &status, 0))
    {
        throw SeashellException("Process: waitpid failed");
    }

    return status;
}


