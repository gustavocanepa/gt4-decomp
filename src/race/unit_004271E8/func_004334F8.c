struct E { int a, b, c; int pad[9]; };
int func_004334F8(struct E *t, unsigned i) {
    struct E *e;
    if (i < 10u) { e = &t[i]; return e->c; }
    return 0x157529FF;
}
