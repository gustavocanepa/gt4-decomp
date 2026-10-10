struct R { char d[0x14C]; };
struct S { char pad[0x5A8]; struct R *tbl; };
char *func_004F6D18(struct S *s, int i) {
    struct R *e;
    if (i >= 16) i = 15;
    e = s->tbl + i;
    return (char *)e + 0x1D8;
}
