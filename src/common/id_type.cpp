#include <string>

#include <log4cpp/Category.hh>
#include <crossguid/guid.hpp>

#include "common/id_type.h"

namespace KevinQuest {
    IdType::IdType() {
        logger.debugStream() << "created new id: " << __init.str();
    }
    
    IdType::~IdType() {
        logger.debugStream() << "deleting id: " << __init.str();
    }

    IdType::IdType(const std::string &guid) {
        if (__init.isValid()) {
            logger.debugStream() << "created new id: " << __init.str();
        } else {
            logger.fatalStream() << "unable to create id from string: " << guid;
        }
    }
}