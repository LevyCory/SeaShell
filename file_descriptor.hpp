#ifndef __seashell_file_descriptor_h__
#define __seashell_file_descriptor_h__

#include <string_view>

#include "common.hpp"

class FileDescriptor
{
public:
    FileDescriptor();
    explicit FileDescriptor(int fd);
    FileDescriptor(std::string_view path, int flags);
    ~FileDescriptor();
    FileDescriptor(const FileDescriptor&) noexcept = delete;
    FileDescriptor& operator= (const FileDescriptor&) noexcept = delete;
    FileDescriptor(FileDescriptor&& other) noexcept;
    FileDescriptor& operator= (FileDescriptor&& other) noexcept;

    //bool operator==(FileDescriptor& other) const { return this->_fd == other._fd; }
    bool operator==(const FileDescriptor& other) const { return this->_fd == other._fd; }
    //bool operator!=(FileDescriptor& other) const { return this->_fd != other._fd; }
    bool operator!=(const FileDescriptor& other) const { return this->_fd != other._fd; }

    static FileDescriptor& in();
    static FileDescriptor& out();
    static FileDescriptor& err();

    void dup(const FileDescriptor& oldfd);

    int get();

private:
    int _fd;
};


#endif /* __seashell_file_descriptor_h__ */
