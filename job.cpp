#include "job.hpp"

Job::Job(std::vector<ShellCommand>&& commands, Pipe::uptr&& pipe) :
    _commands(std::move(commands)),
    _pipe(std::move(pipe)),
    _status(JobStatus::Ready)
{}
