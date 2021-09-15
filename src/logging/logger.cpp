#include "logging/logger.h"

#include <string>
#include <iostream>

#include <log4cpp/Layout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>


namespace KevinQuest::Logging {
    Logger::Logger(
        const std::string &name,
        log4cpp::Layout *layout
    ): category(log4cpp::Category::getInstance(name)) {
        log4cpp::OstreamAppender *appender  = new log4cpp::OstreamAppender(name, &std::cout);
        appender->setLayout(layout);

        category.setAppender(appender);
        category.setPriority(log4cpp::Priority::DEBUG);
    }

    void Logger::debug(const std::string &msg) const {
        this->category.debugStream() << this->codeLocation() << " " << msg << "\n";
    }

    void Logger::info(const std::string &msg) const {
        this->category.infoStream() << msg << "\n";
    }

    void Logger::error(const std::string &msg) const {
        this->category.errorStream() << msg << "\n";
    }
}