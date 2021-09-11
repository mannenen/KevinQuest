#ifndef LOGGING_H
#define LOGGING_H

#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>


#ifdef DEBUG
    #include <log4cpp/OstreamAppender.hh>
#endif

// use the NT Event Log if we're on Windows, otherwise just log to a file 
#ifdef WIN32
    #include <log4cpp/NTEventLogAppender.hh>
#else
    #include <log4cpp/FileAppender.hh>
#endif

#define CODE_LOCATION __FILE__:__LINE__



#endif // LOGGING_H