struct Block {
    unsigned int size;
    Block *next;
};

struct Heap {
    char pad[0x40];
    Block *func_00575DA0;
};

extern "C" Block *func_00575870(Heap *h, Block *a, Block *b);

extern "C" void func_005758B0(Heap *h, Block *b)
{
    Block *prev = 0;
    Block *cur;
    Block *next;
    Block *m = b;
    for (cur = h->func_00575DA0; cur != 0; cur = next) {
        next = cur->next;
        if (b < cur) {
            break;
        }
        prev = cur;
    }
    b->next = cur;
    if (prev == 0) {
        h->func_00575DA0 = b;
    } else {
        prev->next = b;
        m = func_00575870(h, prev, b);
    }
    if (m != 0) {
        func_00575870(h, m, cur);
    }
}
