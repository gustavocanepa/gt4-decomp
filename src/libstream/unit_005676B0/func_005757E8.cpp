struct Block {
    unsigned int size;
    Block *next;
};

struct Heap {
    char pad[0x40];
    Block *func_00575DA0;
};

extern "C" Block *func_005757E8(Heap *h, unsigned int size) {
    Block *b = h->func_00575DA0;
    Block *prev = 0;
    Block *found = 0;
    if (b) {
        do {
            Block *next = b->next;
            Block *link = next;
            if (b->size >= size) {
                found = b;
                if (b->size >= size + 8) {
                    unsigned int rest = b->size - size - 4;
                    b = (Block *)((char *)found + (size / 4) * 4 + 4);
                    found->size = size;
                    b->size = rest;
                    b->next = next;
                    link = b;
                }
                if (!prev)
                    h->func_00575DA0 = link;
                else
                    prev->next = link;
                break;
            }
            prev = b;
            b = next;
        } while (b);
    }
    return found;
}
