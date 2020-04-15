#ifndef __seashell_common_hpp__
#define __seashell_common_hpp__

#include <vector>
#include <string>
#include <unistd.h>

#include "csh_exceptions.hpp"

#define __optional [[maybe_unused]]
#define __fallthrough [[fallthrough]]
#define __nodiscard [[nodisacard]]

using argv_t = std::vector<std::string>;

constexpr pid_t CHILD_PROCESS_ID = 0;
constexpr pid_t INVALID_PROCESS_ID = -1;

constexpr int LIBC_SUCCESS = 0;

constexpr int INVALID_FILE_DESCRIPTOR = -1;

constexpr size_t COMMAND_BUFFER_SIZE = 4096;

#endif /* __seashell_common_hpp__ */
