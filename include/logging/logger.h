#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <sstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/Layout.hh>

#include <log4cpp/BasicLayout.hh>

namespace KevinQuest::Logging {
    class Logger {
        public:
            Logger(
                const std::string &name, 
                log4cpp::Layout *layout = new log4cpp::BasicLayout()
            );

            virtual void debug(const std::string &) const;
            virtual void info(const std::string &) const;
            virtual void error(const std::string &) const;

        protected:
            const std::string codeLocation() const {
                std::ostringstream result = std::ostringstream();
                result << "[" << __FILE__ << "::" << __FUNCTION__ << "]{" << __LINE__ << "} ";

                return result.str();
            }

        private:
            log4cpp::Category &category;
    };
}

#endif // LOGGER_H