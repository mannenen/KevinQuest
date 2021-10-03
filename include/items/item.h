#ifndef KEVIN_QUEST_ITEM_H
#define KEVIN_QUEST_ITEM_H

#include <iostream>

#include "common/id_type.h"
#include "event/emitter.h"
#include "event/event.h"

namespace KevinQuest::Items {
    class Item: public KevinQuest::Event::EventEmitter {
        public:
        Item(): 
            _id(KevinQuest::IdType()) {};
        ~Item() {};

        inline const KevinQuest::IdType &id() const { return _id; }

        private:
        const KevinQuest::IdType &_id;
    };

    std::ostream &operator<<(std::ostream &out, const Item &i) {
        return out << i.id();
    }
}

#endif // KEVIN_QUEST_ITEM_H