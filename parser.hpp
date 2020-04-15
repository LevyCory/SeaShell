#ifndef __seashell_parser_hpp__
#define __seashell_parser_hpp__


#include "command.h"
#include "file_descriptor.hpp"

class Parser
{
public:

    argv_t parse_command(const std::string& command);
    
private:

}

#endif /* __seashell_parser_hpp__ */
