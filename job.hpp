#ifndef __seashell_job_hpp__
#define __seashell_job_hpp__

#include <vector>

#include "pipe.hpp"
#include "command.hpp"

class Job final
{
    Job(std::vector<ShellCommand>&& commands, Pipe::uptr&& pipe);
    ~Job() = default;

    int start() const;

private:
    enum class JobStatus : uint8_t
    {
        Ready = 0,
        Running,
        Stopped
    };

private:
    std::vector<ShellCommand> _commands;
    Pipe::uptr _pipe;
    JobStatus _status;
};

#endif /* __seashell_job_hpp__ */
