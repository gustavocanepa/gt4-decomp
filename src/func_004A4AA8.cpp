typedef unsigned long long u64;

struct func_004A4AA8_Obj {
    char pad0[0x1C0];
    u64 tex0;
    char pad1[0x2C5 - 0x1C8];
    signed char mode;
};

extern "C" void func_004A4AA8(func_004A4AA8_Obj *p) {
    if (p->mode != 1) {
        p->tex0 |= 1ULL << 34;
    } else {
        u64 t = p->tex0;
        switch ((int)((t >> 20) & 0x3F)) {
        case 19: case 20: case 27: case 36: case 44:
            p->tex0 = t & ~(1ULL << 34);
            return;
        default:
            p->tex0 = t | (1ULL << 34);
            return;
        }
    }
}
