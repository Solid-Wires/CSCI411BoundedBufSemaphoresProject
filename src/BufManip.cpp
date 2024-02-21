#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {
    // Insert an item into the buffer.
    int InsertItem(buffer_item item) {
        try {
            shared.buf[shared.in%BUFF_SIZE] = item;
            return 0;
        } catch (...) {}
        return -1;
    }

    // Take an item out of the buffer.
    int RemoveItem(buffer_item *item) {
        try {
            item = &shared.buf[shared.out%BUFF_SIZE];
            return 0;
        } catch (...) {}
        return -1;
    }
} 
