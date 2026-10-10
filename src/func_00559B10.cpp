/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;

struct Sub {
    char pad[0x30];
    u16 *table;
};

struct Obj {
    char pad[0x14];
    Sub *sub;
};

extern "C" void *func_00559B10(Obj *o, u32 idx) {
    u16 *t = o->sub->table;
    if (t == 0 || ((u32)t & 1))
        return 0;
    if (t[0] < idx)
        return 0;
    u16 off = t[idx + 1];
    if (off == 0xFFFF)
        return 0;
    return (char *)t + off;
}
