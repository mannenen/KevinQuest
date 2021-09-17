#ifndef KEVIN_QUEST_HOLDABLE_H
#define KEVIN_QUEST_HOLDABLE_H

namespace KevinQuest::Items {
    class Holdable {
        public:
            virtual bool isHeld() const;
    };
}

#endif