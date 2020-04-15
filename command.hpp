#ifndef __sheshell_command_hpp__
#define __sheshell_command_hpp__

#include <vector>
#include <string>

#include "process.hpp"
#include "file_descriptor.hpp"

class ShellCommand final
{
public:
    ShellCommand(
        const std::string& exec,
        argv_t&& args,
        FileDescriptor& file_in = FileDescriptor::in(),
        FileDescriptor& file_out = FileDescriptor::out(),
        FileDescriptor& file_err = FileDescriptor::err()
    );

    const FileDescriptor& get_stdin() const { return _stdin; }
    const FileDescriptor& get_stdout() const { return _stdout; }
    const FileDescriptor& get_stderr() const { return _stderr; }
    const std::string& get_executable() const { return _executable; }
    const argv_t& get_args() const { return _arguments; }

    Process run() const;

private:
    std::vector<char*> _create_c_argv() const;

private:
    std::string _executable;
    argv_t _arguments;

    FileDescriptor& _stdin;
    FileDescriptor& _stdout;
    FileDescriptor& _stderr;
};

#endif /*__sheshell_command_hpp__ */
