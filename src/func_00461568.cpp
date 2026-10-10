struct Pair {
    int a;
    int b;
    Pair(int x, int y) : a(x), b(y) {}
    Pair(const Pair &p) : a(p.a), b(p.b) {}
};

struct Global {
    char pad[0x10];
    int m10;
    int m14;
};

struct Slot {
    Pair *pair;
    int m4;
    int m8;
};

extern Global *D_008468D4;
extern Slot D_006239AC[];

Pair func_00461568(int idx) __asm__("func_00461568");

Pair func_00461568(int idx) {
    Global *g = D_008468D4;
    if (g == 0)
        return Pair(0, 0);
    if (idx == -1)
        return Pair(g->m14, g->m10);
    Pair *p = D_006239AC[idx].pair;
    if (p == 0)
        return Pair(0, 0);
    return *p;
}
