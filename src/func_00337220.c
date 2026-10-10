struct R { char d[0x214]; };
struct S { char pad[0xE50C]; struct R tbl[1]; };
extern struct R D_00622B60;
struct R *func_00337220(struct S *s, int i) {
    struct R *e;
    int k;
    if (i < 0x100) return &D_00622B60;
    k = i - 0x100;
    e = &s->tbl[k];
    return e;
}
