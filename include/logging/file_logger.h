#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <fstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/FileAppender.hh>

#include "logger.h"

namespace KevinQuest::Logging {
    class FileLogger: protected Logger {
        public:
            FileLogger(
                std::string &name,
                const std::string &filename,
                log4cpp::Layout *layout = new log4cpp::BasicLayout()
            );
            ~FileLogger() {}

            void debug(const std::string &msg) const;
            void info(const std::string &msg) const;
            void error(const std::string &msg) const;

        private:
            log4cpp::Category m_logger;
            void log(const std::string &tag, const std::string &msg) const;
    };
}

#endif // FILE_LOGGER_H