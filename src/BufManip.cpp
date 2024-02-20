#include "../inc/Common.h"
using namespace BoundedBufProj;

// Insert an item into the buffer.
int BoundedBufProj::InsertItem(buffer_item item[BUFF_SIZE]) {
    try {
        shared.buf = item;
        return 0;
    } catch (...) {}
    return -1;
}

// Pop an item from the buffer.
int BoundedBufProj::RemoveItem(buffer_item *item[BUFF_SIZE]) {
    try {
        //item = shared.buf;
        return 0;
    } catch (...) {}
    return -1;
}
