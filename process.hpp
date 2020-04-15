#ifndef __seashell_process_hpp__
#define __seashell_process_hpp__

#include <unistd.h>

#include "file_descriptor.hpp"
#include "common.hpp"

class Process final
{
public:
    Process(
        char* prog,
        char** arguments,
        FileDescriptor& in,
        FileDescriptor& out,
        FileDescriptor& err
    );
    ~Process();

    int wait();

private:
    pid_t _process_id;
    int _status;
};

#endif /* __seashell_process_hpp__ */
