struct Rgba {
    unsigned char r, g, b, a;
};

extern "C" Rgba D_0084B080[256];

extern "C" void func_004A91D0(void) {
    Rgba *e = D_0084B080;
    for (int i = 0; i < 256; i++, e++) {
        int v = (i & 0xE7) | ((i & 0x08) << 1) | ((i & 0x10) >> 1);
        e->r = v;
        e->g = v;
        e->b = v;
        e->a = v;
    }
}
