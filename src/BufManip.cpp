#include "../inc/Common.h"
namespace BoundedBufProj {
    // Insert an item into the buffer.
    int InsertItem(buffer_item item) {
        try {
            std::memcpy(shared.buf, item, BUFF_SIZE);
            return 0;
        } catch (...) {}
        return -1;
    }

    // Pop an item from the buffer.
    int RemoveItem(buffer_item *item) {
        try {
            std::memcpy(item, shared.buf, BUFF_SIZE);
            return 0;
        } catch (...) {}
        return -1;
    }
} 
