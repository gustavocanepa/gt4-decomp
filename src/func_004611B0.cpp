typedef int s32;

struct G { s32 m0; s32 m4; void *h; };
extern G D_008468D0;
extern "C" void func_00559C80(void *);

extern "C" void func_004611B0(void) {
    G *g = &D_008468D0;
    if (g->h != 0) {
        func_00559C80(g->h);
        g->h = 0;
    }
    g->m0 = -1;
}
