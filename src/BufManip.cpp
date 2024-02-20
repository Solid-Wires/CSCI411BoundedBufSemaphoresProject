#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {
    // Insert an item into the buffer.
    int InsertItem(buffer_item item) {
        try {
            memcpy(shared.buf, item, BUFF_SIZE);
            return 0;
        } catch (...) {}
        return -1;
    }

    // Pop an item from the buffer.
    int RemoveItem(buffer_item *item) {
        try {
            memcpy(item, shared.buf, BUFF_SIZE);
            return 0;
        } catch (...) {}
        return -1;
    }
} 
