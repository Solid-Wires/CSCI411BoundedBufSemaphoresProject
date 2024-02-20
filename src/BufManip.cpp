#include "../inc/Common.h"
using namespace BoundedBufProj;

// Insert an item into the buffer.
int BoundedBufProj::InsertItem(buffer_item item) {
    try {
        std::memccpy(shared.buf, item, BUFF_SIZE);
        return 0;
    } catch (...) {}
    return -1;
}

// Pop an item from the buffer.
int BoundedBufProj::RemoveItem(buffer_item *item) {
    try {
        std::memccpy(item, shared.buf, BUFF_SIZE);
        return 0;
    } catch (...) {}
    return -1;
}
