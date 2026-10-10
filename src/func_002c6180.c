struct E { int v; char d[0x20]; };
struct G { char pad[0x38]; int w; int pad3c; int h; char pad2[8]; struct E *e; };
int func_002C6180(struct G *g, int x, int y, int z) {
    struct E *e;
    int h = g->h;
    e = g->e + ((g->w * h * x) + (h * y) + z);
    return e->v;
}
