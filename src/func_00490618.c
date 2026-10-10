struct R { char d[0x40]; };
struct B { char pad[0x18]; struct R *tbl; };
struct S { char pad[0xC]; struct B *b; char pad2[0x1c]; int idx; };
struct R *func_00490618(struct S *s) {
    struct B *b = s->b;
    struct R *e;
    if (b == 0) return 0;
    e = b->tbl + s->idx;
    return e;
}
