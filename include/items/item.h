#ifndef KEVIN_QUEST_ITEM_H
#define KEVIN_QUEST_ITEM_H

#include <string>

namespace KevinQuest::Items {
    class Item {
        public:
        const std::string &ToString() const;

        private:
        Item() {};
        ~Item() {};

        
    };
}

#endif // KEVIN_QUEST_ITEM_H