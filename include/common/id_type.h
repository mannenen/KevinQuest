#ifndef KEVIN_QUEST_ID_TYPE_H
#define KEVIN_QUEST_ID_TYPE_H

#include <string>
#include <iostream>

#include <log4cpp/Category.hh>
#include <crossguid/guid.hpp>


namespace KevinQuest {
    class IdType {
        public:
            IdType();
            ~IdType();

            inline const std::string &asString() const { return __init.str(); }
        
        protected:
            IdType(const std::string &);
        
        private:
            const xg::Guid __init = xg::newGuid();
            log4cpp::Category &logger = log4cpp::Category::getInstance("kevin_quest");
    };

    std::ostream &operator<<(std::ostream &out, const IdType &i) {
        return out << i.asString();
    }
}

#endif // KEVIN_QUEST_ID_TYPE_H