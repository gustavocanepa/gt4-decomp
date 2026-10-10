struct Obj {
    char pad0[0x34];
    int m34;
    char pad38[4];
    int m3C;
};

extern "C" unsigned long func_00578560(void);

extern "C" int func_001CBAD0(Obj *o, int x) {
    if (o->m3C == x)
        o->m34 = x;
    else if (o->m34 != x)
        return 0;
    o->m3C += func_00578560() & 0xFFFFFFFF;
    if (o->m3C == 0)
        o->m3C = 1;
    return 1;
}
