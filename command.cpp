#include "command.hpp"

ShellCommand::ShellCommand(
        const std::string& exec,
        argv_t&& args,
        FileDescriptor& file_in,
        FileDescriptor& file_out,
        FileDescriptor& file_err
) :
    _executable(exec),
    _arguments(std::move(args)),
    _stdin(file_in),
    _stdout(file_out),
    _stderr(file_err)
{}

std::vector<char*> ShellCommand::_create_c_argv() const
{
    std::vector<char*> argv(_arguments.size() + 2);    
    argv[0] = (const_cast<char*>(_executable.c_str()));
    argv[_arguments.size() + 1] = 0;

    for (const auto& arg : _arguments)
        argv.push_back(const_cast<char*>(arg.c_str()));

    return argv;
}

Process ShellCommand::run() const
{
    auto argv = _create_c_argv();

    return Process(
        argv[0],
        argv.data(),
        _stdin,
        _stdout,
        _stderr
    );
}
