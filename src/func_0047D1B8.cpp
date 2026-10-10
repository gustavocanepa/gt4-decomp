struct Pair { int a; int b; };

struct Obj {
    char pad0[8];
    int f8;
    Pair cur;
    Pair prev;
    unsigned char flags[128];
    char pad9c[0x80];
    int f11c;
    int f120;
};

extern "C" void func_0047D1B8(Obj *p) {
    int i;
    p->prev = p->cur;
    for (i = 0; i < 128; i++) {
        p->flags[i] = (p->flags[i] & 1) | ((p->flags[i] & 1) << 1);
    }
    p->f11c = 0;
    p->f120 = 0;
    p->f8 = 0;
}
