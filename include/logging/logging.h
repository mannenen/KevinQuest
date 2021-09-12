#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <unordered_map>
#include <mutex>

#include "logger.h"




namespace KevinQuest::Logging {
    class LoggerFactory {
        public:
            LoggerFactory(const LoggerFactory &) = delete;
            void operator=(const LoggerFactory &) = delete;

            static Logger *GetLogger(const std::string &loggerName);

        protected:
            LoggerFactory();


        private:

            static LoggerFactory *m_Instance;
            static std::mutex m_Mutex;
            std::unordered_map<std::string, Logger> &mLoggerCache;
    };
    
    Logger *LoggerFactory::GetLogger(const std::string &loggerName) {
        
        if (m_Instance == nullptr) {
            m_Instance = new LoggerFactory();
        }

        if (m_Instance->mLoggerCache.at(loggerName) != nullptr) {

        }
    }
}




#endif // LOGGING_H