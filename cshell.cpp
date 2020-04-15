#include <functional>
#include <filesystem>
#include "command.hpp"
#include "cshell.hpp"

namespace fs = std::filesystem;

SeaShell::SeaShell() :
    _keep_running(true),
    _command_buffer(COMMAND_BUFFER_SIZE, '\0')
{
    _register_callbacks();
}

void SeaShell::_register_callbacks()
{
    _internal_callbacks["exit"] = std::bind(&SeaShell::_exit, this, std::placeholders::_1);
}

void SeaShell::_print_prompt()
{
    std::cout << "[" << fs::current_path() << "] ";
}

void SeaShell::run()
{
    while (_keep_running)
    {
        _print_prompt();

        try
        {
            std::getline(std::cin, _command_buffer); 

            callback_map::iterator cmd = _internal_callbacks.find(_command_buffer);
            if (cmd != _internal_callbacks.end())
            {
                cmd->second(argv_t());
                continue;
            }

            ShellCommand sh_cmd(_command_buffer, argv_t());
            sh_cmd.run();
        }

        catch (const SeashellException& error)
        {
            std::cerr << error.what() << std::endl;
        }

        catch (const std::exception& error)
        {
        }
    }
}
