#include <sstream>

#include "logging/basic_logger.h"
#include "logging/file_logger.h"
#include "logging/logger.h"

namespace logging = KevinQuest::Logging;

int main(int argc, char *argv[]) {
    DEBUG_LOG("this is a debug message");
    ERROR_LOG("this is an error message");

    logging::FileLogger fileLogger = logging::FileLogger("main_file", "debug.log");
    fileLogger.debug("this is a debug log to a file");
    fileLogger.info("this is an information log to a file");
    fileLogger.error("this is an error log to a file");

    logging::Logger logger = logging::Logger("main");
    logger.debug("this is a debug log to std::cout");
    logger.info("this is an informational log to std::cout");
    logger.error("this is an error log to a file");

    std::ostringstream os = std::ostringstream();
    os << "\nindex\tvalue\n";

    for (int i = 0; i < argc; i++) {
        os << i << ":\t" << argv[i] << "\n";
    }

    logger.info(os.str());

    return 0;
}