#include "buffer.hpp"

#include "core/Buffer.hpp"
#include "core/PegasusInst.hpp"
#include "core/PegasusCore.hpp"
#include "include/ActionTags.hpp"

#include "sparta/utils/LogUtils.hpp"

namespace pegasus
{
    UnifiedBuffer::UnifiedBuffer(
}

UnifiedBuffer::UnifiedBuffer(float buffer_size) {
    capacity = buffer_size;
    is_main_memory = false;

    sender_queue = new std::vector<request>();
    served_queue = new std::vector<request>();
    waiting_queue = new std::vector<request>();
    request_queue = new std::vector<request>();
}

UnifiedBuffer::~UnifiedBuffer() {
    delete sender_queue;
    delete served_queue;
    delete waiting_queue;
    delete request_queue;
}

void UnifiedBuffer::Cycle() {
    request req;
    while (!served_queue->empty()) {
        req = served_queue->front();
        pop_front(*served_queue);
        sender_queue->push_back(MakeRequest(req.order, req.size));
    }
}

