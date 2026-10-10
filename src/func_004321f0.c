struct E { int a; char pad[0x28]; };
int func_004321F0(struct E *t, unsigned i) {
    struct E *e;
    if (i < 10u) { e = &t[i]; return e->a; }
    return 0x157529FF;
}
