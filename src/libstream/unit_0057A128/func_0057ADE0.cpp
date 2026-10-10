struct BitWriter {
    int unk0;
    unsigned char *ptr;
    unsigned char cur;
    int used;
};

extern "C" void func_0057ADE0(BitWriter *w, unsigned long value, int nbits) {
    unsigned char *p = w->ptr;
    unsigned long cur = w->cur;
    int used = w->used;
    value <<= 64 - nbits;
    while (nbits) {
        int n = 8 - used;
        if (!(n < nbits))
            n = nbits;
        cur |= value >> (56 + used);
        used += n;
        value <<= n;
        nbits -= n;
        if (used == 8) {
            *p++ = cur;
            cur = 0;
            used = 0;
        }
    }
    if (used)
        *p = cur;
    w->ptr = p;
    w->cur = cur;
    w->used = used;
}
