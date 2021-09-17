#ifndef KEVIN_QUEST_TRADABLE_H
#define KEVIN_QUEST_TRADABLE_H

namespace KevinQuest::Items {
    class Tradable {
        public:
        virtual int SalePrice() const;
    };
}

#endif