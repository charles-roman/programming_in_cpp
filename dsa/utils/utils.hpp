#include <string>

#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils {

enum ErrorType {
    MallocError = 0,
    EmptyError,
    IndexError,
    SizeError
};

void throw_error(const std::string &func, const int err);
    
}   // namespace utils (utilities [library])

#endif  // UTILS_HPP