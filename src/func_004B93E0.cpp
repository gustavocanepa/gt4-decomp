typedef unsigned short u16;

extern "C" int func_004B93E0(const u16 *s) {
    int c = *s;
    int base = 0xFF41;
    if (c >= base && c <= 0xFF5A)
        return c - base + 'a';
    base = 0xFF21;
    if (c >= base && c <= 0xFF3A)
        return c - base + 'a';
    return 0;
}
