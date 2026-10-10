/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Block { u32 size; Block *next; };

extern "C" Block *func_00575870(void *heap, Block *b, Block *n) {
    Block *after = (Block *)((char *)b + (b->size >> 2 << 2) + 4);
    if (after != n) return 0;
    b->size = b->size + n->size + 4;
    b->next = n->next;
    return b;
}
