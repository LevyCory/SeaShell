#ifndef __seashell_pipe_hpp__
#define __seashell_pipe_hpp__

#include <memory>

#include "file_descriptor.hpp"

class Pipe final
{
public:
    using uptr = std::unique_ptr<Pipe>;

    Pipe();
    ~Pipe() = default;

    const FileDescriptor& read_end() { return _out; };
    const FileDescriptor& write_end() { return _in; };

private:
    typedef enum _PipeFd
    {
        FD_READ = 0,
        FD_WRITE,
        FD_COUNT
    } PipeFd;

private:
    FileDescriptor _out;
    FileDescriptor _in;
};

#endif /* __seashell_pipe_hpp__ */
