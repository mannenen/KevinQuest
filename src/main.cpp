#include <sstream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "common/id_type.h"

int main(int argc, char *argv[]) {
    log4cpp::PropertyConfigurator::configure("log4cpp.properties");

    log4cpp::Category &logger = log4cpp::Category::getInstance("kevin_quest");
    logger.info("Initialized logging correctly.");

#ifdef NDEBUG
    for (int i = 0; i < argc; i++) {
        logger.debug("\t%d\t%s", i, argv[i]);
    }
#endif

    KevinQuest::IdType id = KevinQuest::IdType();
    
    return 0;
}
