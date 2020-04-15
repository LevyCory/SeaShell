#ifndef __seashell_cshell_hpp__
#define __seashell_cshell_hpp__

#include <string>
#include <iostream>
#include <functional>
#include <unordered_map>

#include "common.hpp"


class SeaShell final
{
public:
    using callback_t = std::function<void(__optional const argv_t&)>;
    using callback_map = std::unordered_map<std::string, callback_t>;

    SeaShell();
    ~SeaShell() = default;

    void run();

private:
    void _register_callbacks();
    void _exit(__optional const argv_t& args) { _keep_running = false; }

    static void _print_prompt();

private:
    bool _keep_running;
    std::string _command_buffer;
    callback_map _internal_callbacks;
};

#endif /* __seashell_cshell_hpp__ */
