#include "include/common/id_type.h"
#include "include/event/event.h"
#include "include/event/emitter.h"

namespace KevinQuest::Event {
    Event::Event(const EventEmitter &source, void (*callback)()):
        event_id(IdType()), source(source), callback(callback) {}
}