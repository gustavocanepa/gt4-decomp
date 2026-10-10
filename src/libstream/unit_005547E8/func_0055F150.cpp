struct Bits {
    int f0;
    unsigned char count;
    unsigned char bits[1];
};

extern "C" void func_0055F150(Bits *b, int i, int on) {
    if (i < 0 || i >= b->count) {
        return;
    }
    unsigned char *p = b->bits;
    p += i >> 3;
    int m = 1 << (i & 7);
    int v = *p | m;
    if (!on) {
        v -= m;
    }
    *p = v;
}
