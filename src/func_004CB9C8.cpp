struct Cursor {
    char pad[8];
    unsigned int index;
    unsigned int offset;
};

struct Stream {
    char pad[0x50];
    unsigned int blockSize;
    char pad2[0x14];
    int count;
    char pad3[4];
    int shift;
};

extern "C" void func_004CB900(Stream *s, Cursor *c, unsigned int block);

extern "C" void func_004CB9C8(Stream *s, Cursor *c, unsigned int n)
{
    n += c->offset;
    unsigned int q = n / s->blockSize;
    unsigned int r = n % s->blockSize;
    unsigned int i = c->index + q;
    c->offset = r;
    c->index = i;
    unsigned int block = i >> s->shift;
    c->index = i & (s->count - 1);
    return func_004CB900(s, c, block);
}
