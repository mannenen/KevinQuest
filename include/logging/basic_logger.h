#ifndef BASIC_LOGGER_H
#define BASIC_LOGGER_H

#include <iostream>
#include <string>

namespace KevinQuest::Logging::__internal {
    void log(std::ostream &s, const char *file, const char *function, const int line, const std::string &msg) {
        s << "[" << file << "::" << function << "]{" << line << "} " << msg << "\n";
    }
}

#define ERROR_LOG(msg) KevinQuest::Logging::__internal::log(std::cerr, __FILE__, __FUNCTION__, __LINE__, msg);
#define DEBUG_LOG(msg) KevinQuest::Logging::__internal::log(std::cout, __FILE__, __FUNCTION__, __LINE__, msg);


#endif // BASIC_LOGGER_H