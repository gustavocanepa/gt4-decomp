extern "C" unsigned int func_004944B0(const unsigned char *p, unsigned int len) {
    const unsigned char *end = p + len;
    unsigned int h = 0;
    while (p < end) {
        h = (h << 4) + *p++;
        unsigned int g = h & 0xF0000000;
        if (g) {
            h ^= g >> 24;
        }
        h &= ~g;
    }
    return h;
}
