struct Pool {
    unsigned int blockSize;
    char *start;
    unsigned int size;
    int count;
};

extern "C" void func_004B3BE8(Pool *p, unsigned int blockSize, char *start, unsigned int size) {
    if (p->blockSize == 0)
        p->blockSize = blockSize;
    size &= ~3;
    int *q = (int *)(start + size) - 1;
    char *c = start;
    int n = 0;
    for (; (char *)q >= c + p->blockSize; c += p->blockSize) {
        *q-- = -4;
        n++;
    }
    p->start = start;
    p->size = size;
    p->count = n;
}
