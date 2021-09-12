
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
        std::string &name,
        const std::string &filename,
        log4cpp::Layout *layout = new log4cpp::BasicLayout()
    ): Logger(name, layout) {
        log4cpp::FileAppender *appender = new log4cpp::FileAppender(name, filename);
        appender->setLayout(layout);

        log4cpp::Category &root = log4cpp::Category::getRoot();
        m_logger = log4cpp::Category::getInstance(name);
        this->m_logger.setAppender(appender);
        this->m_logger.setPriority(log4cpp::Priority::INFO);
    }

    void FileLogger::log(const std::string &tag, const std::string &msg) const {
        std::ostringstream ss = std::ostringstream();
        ss << tag << msg << std::endl;

        this->m_logger << ss.str();
    }

    void FileLogger::debug(const std::string &msg) const {
        std::string withLocation = this->codeLocation() + " " + msg;
        this->log(log4cpp::Priority::getPriorityName(log4cpp::Priority::INFO), withLocation);
    }

    void FileLogger::info(const std::string &msg) const {
        this->log(log4cpp::Priority::getPriorityName(log4cpp::Priority::NOTICE), msg);
    }

    void FileLogger::error(const std::string &msg) const {
        this->log(log4cpp::Priority::getPriorityName(log4cpp::Priority::ERROR), msg);
    }
}