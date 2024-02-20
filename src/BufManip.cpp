#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {

    // Insert an item into the buffer.
    int InsertItem(buffer_item item) {
        try {
            copy(item, item + BUFF_SIZE, shared.buf);
            return 0;
        } catch (...) {}
        return -1;
    }

    // Pop an item from the buffer.
    int RemoveItem(buffer_item *item) {
        try {
            copy(shared.buf, shared.buf + BUFF_SIZE, item);
            return 0;
        } catch (...) {}
        return -1;
    }
} 
