#include "../inc/Common.h"
using namespace std;

// Defined within namespace
namespace BoundedBufProj {
    // Insert an item into the first empty slot on the buffer.
    // shared.in gets incremented, and Modulo BUFF_SIZE wraps around
    r_code InsertItem(buffer_item item) {
        try {
            shared.buf[shared.in%BUFF_SIZE] = item;
            shared.in++;
            return 0;
        } catch (...) {}
        return -1;
    }

    // Take an item out of the first full slot from the buffer.
    // shared.out gets incremented, and Modulo BUFF_SIZE wraps around
    r_code RemoveItem(buffer_item *item) {
        try {
            cout << "item we're removing: " << shared.buf[shared.out%BUFF_SIZE] << endl;
            item = &shared.buf[shared.out%BUFF_SIZE];
            cout << "item we just removed: " << item;
            shared.out++;
            return 0;
        } catch (...) {}
        return -1;
    }
} 
