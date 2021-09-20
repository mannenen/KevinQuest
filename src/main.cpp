#include <sstream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

int main() {
    log4cpp::PropertyConfigurator::configure("log4cpp.properties");

    log4cpp::Category &logger = log4cpp::Category::getInstance("kevin_quest");
    logger.info("Initialized logging correctly.");
    
    return 0;
}
