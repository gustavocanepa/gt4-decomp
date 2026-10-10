/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Clut {
    char pad[0x1C];
    unsigned int *table;
};

extern "C" void RacePriusHybridDisplay__apply_level_patch(Clut *c, int row, int base, int n, float thr, unsigned int on, unsigned int off)
{
    if (c->table == 0) {
        return;
    }
    int start = row * 16 + base;
    for (int i = 0; i < n; i++) {
        int v = start + i;
        int k = (v & 0xE7) | ((v & 8) << 1) | ((v & 0x10) >> 1);
        unsigned int *p = &c->table[k];
        if ((float)(i + 1) / (float)n <= thr) {
            *p = on;
        } else {
            *p = off;
        }
    }
}
