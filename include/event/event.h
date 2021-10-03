#ifndef KEVIN_QUEST_EVENT_H
#define KEVIN_QUEST_EVENT_H

#include <string>

#include "include/common/id_type.h"

#include "emitter.h"

namespace KevinQuest::Event {
    class Event {
        public:
        Event(const EventEmitter &, void (*callback)());
        ~Event() {};

        private:
        const KevinQuest::IdType &event_id;
        const EventEmitter &source;
        void (*callback)();
    };
}

#endif