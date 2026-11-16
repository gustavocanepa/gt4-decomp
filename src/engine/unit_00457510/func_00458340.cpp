/* True when no block of the (already relocated) table reaches `limit`:
   every row is scanned from its first block pointer, and a block whose
   offset + size is at or past the limit sets the flag. The two fields are
   read into locals, size first, which is what puts the offset load first
   and the sum in the offset's register. */
struct Block {
    int offset;
    unsigned int size;
};

struct Header {
    int f0;
    Header *self;
    char pad8[8];
    unsigned short rows;
    unsigned short cols;
    char pad14[0xC];
    Block *blocks[1];
};

extern "C" bool func_00458340(Header *h, unsigned int limit) {
    if (h != h->self) return 0;
    bool found = 0;
    for (int i = 0; i < h->rows; i++) {
        Block **p = &h->blocks[i * h->cols];
        for (int j = 0; j < h->cols; j++) {
            Block *b = *p++;
            if (b) {
                unsigned int size = b->size, offset = b->offset;
                found |= offset + size >= limit;
            }
        }
    }
    return !found;
}
