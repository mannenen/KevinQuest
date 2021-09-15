#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <fstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/FileAppender.hh>

#include "logging/logger.h"

namespace KevinQuest::Logging {
    class FileLogger: public Logger {
        public:
            FileLogger(
                const std::string &name,
                const std::string &filename,
                log4cpp::Layout *layout = new log4cpp::BasicLayout()
            );
            ~FileLogger() {}

            void debug(const std::string &msg);
            void info(const std::string &msg);
            void error(const std::string &msg);

        private:
            log4cpp::Category &m_logger;
    };
}

#endif // FILE_LOGGER_H