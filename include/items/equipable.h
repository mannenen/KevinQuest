#ifndef KEVIN_QUEST_EQUIPABLE_H
#define KEVIN_QUEST_EQUIPABLE_H

namespace KevinQuest::Items {
    class Equipable {
        public:
        virtual bool isEquipped() const;
    };
}

#endif