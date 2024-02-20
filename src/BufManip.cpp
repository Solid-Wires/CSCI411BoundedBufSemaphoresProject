#include "../inc/Common.h"
using namespace BoundedBufProj;

buffer_item buffer;

// Insert an item into the buffer.
int BoundedBufProj::InsertItem(buffer_item item) {
    try {
        buffer = item;
        return 0;
    } catch (...) {}
    return -1;
}

// Pop an item from the buffer.
int BoundedBufProj::RemoveItem(buffer_item *item) {
    try {
        //item = shared.buf;
        return 0;
    } catch (...) {}
    return -1;
}
