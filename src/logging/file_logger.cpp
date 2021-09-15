
#include <fstream>
#include <string>
#include <sstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

#include "logging/logger.h"
#include "logging/file_logger.h"


namespace KevinQuest::Logging {
    FileLogger::FileLogger(
        const std::string &name,
        const std::string &filename,
        log4cpp::Layout *layout
    )
    : Logger(name, layout), m_logger(log4cpp::Category::getInstance(name)) {
        log4cpp::FileAppender *appender = new log4cpp::FileAppender(name, filename);
        appender->setLayout(layout);

        m_logger.setAppender(appender);
        m_logger.setPriority(log4cpp::Priority::DEBUG);
    }

    void FileLogger::debug(const std::string &msg) {
        m_logger.debugStream() << this->codeLocation() << " " << msg << "\n";
    }

    void FileLogger::info(const std::string &msg) {
        m_logger.infoStream() << msg << "\n";
    }

    void FileLogger::error(const std::string &msg) {
        m_logger.errorStream() << msg << "\n";
    }
}