#ifndef KEVIN_QUEST_ID_GEN_H
#define KEVIN_QUEST_ID_GEN_H

#include "id_type.h"

namespace KevinQuest::Common {
    class IdGenerator {
        public:
        static const IdType &GenerateNew();
    }
}

#endif