#include "../inc/Common.h"
namespace BoundedBufProj {
    // Insert an item into the buffer.
    int InsertItem(buffer_item item) {
        try {
            shared.buf = item;
            return 0;
        } catch (...) {}
        return -1;
    }

    // Pop an item from the buffer.
    int RemoveItem(buffer_item *item) {
        try {
            item = shared.buf;
            return 0;
        } catch (...) {}
        return -1;
    }
} 
