struct E { char d[0x1c]; };
struct S { char pad[0x30]; int n; int pad2; struct E *tbl; };
struct E *BlockUnit__initialize(struct S *s, int i, int j) {
    struct E *e;
    if (s->tbl != 0 && i >= 0) {
        e = s->tbl + (s->n * j + i);
        if (i < s->n) return e;
    }
    return 0;
}
