#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <sstream>

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/Layout.hh>

#include <log4cpp/BasicLayout.hh>

namespace KevinQuest::Logging::__internal {
    void log(std::ostream &s, const char *file, const char *function, const char *line, const std::string &msg) {
        s << "[" << file << "::" << function << "]{" << line << "} " << msg << std::endl;
    }

    
}
#define ERROR(msg) KevinQuest::Logging::__internal::log(std::cerr, __FILE__, __FUNCTION__, __LINE__, msg);
#define INFO(msg)  KevinQuest::Logging::__internal::log(std::cout, __FILE__, __FUNCTION__, __LINE__, msg);


namespace KevinQuest::Logging {
    class Logger {
        public:
            Logger(
                std::string &name, 
                log4cpp::Layout *layout = new log4cpp::BasicLayout())
                    : m_name(name), m_layout(layout) {}

            virtual void debug(const std::string &) const = 0;
            virtual void info(const std::string &) const = 0;
            virtual void error(const std::string &) const = 0;

        protected:
            const std::string &codeLocation() const {
                std::ostringstream result = std::ostringstream();
                result << "[" << __FILE__ << "::" << __FUNCTION__ << "]{" << __LINE__ << "} ";

                return std::string(result.str());
            }

        private:
            const std::string &m_name;
            log4cpp::Layout *m_layout;
    };
}

#endif // LOGGER_H