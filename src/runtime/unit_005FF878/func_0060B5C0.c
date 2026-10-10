/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Pool {
    unsigned int base;
    unsigned int size;
    unsigned int blockSize;
    unsigned int *freeList;
    int used;
    int count;
};

void func_0060B5C0(struct Pool *p) {
    unsigned int end = p->base + p->size;
    unsigned int m = 63;
    unsigned int cur = (p->base + m) & ~m;
    unsigned int bs = (p->blockSize + m) & ~m;
    unsigned int *prev = 0;
    unsigned int next = cur + bs;
    p->used = 0;
    p->count = 0;
    while (next <= end) {
        *(unsigned int **)cur = prev;
        prev = (unsigned int *)cur;
        cur = next;
        next += bs;
        p->count++;
    }
    p->freeList = prev;
}
