typedef unsigned int u32;

struct Block {
    int unk0;
    int unk4;
    int tag0;
    int tag1;
};

struct Heap {
    Block *start;
    Block *end;
};

// Is b a free block of the heap: 16-byte aligned, inside [start, end), both tags -1. The tag
// constant as a local set one block ahead keeps one -1 register for both compares.
extern "C" bool func_00612C70(Heap *h, Block *b) {
    if ((u32)b & 0xF)
        return false;
    if (b < h->start)
        return false;
    int none = -1;
    if (b >= h->end)
        return false;
    if (b->tag0 != none)
        return false;
    return b->tag1 == none;
}
