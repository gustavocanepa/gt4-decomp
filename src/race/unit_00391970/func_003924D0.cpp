#include "types.h"

/* RaceCarSound::playStart (GT HD name): one-time setup of the car's sound
 * channels, then the per-channel float state is cleared. */

extern "C" void func_00391EB0(void *);
extern "C" s32 func_00559808(void);
extern "C" void func_00559470(s32, s32, s32, s32);
extern "C" void func_00559330(s32);

struct Src { s32 x; char pad[0x120]; };
struct Self {
    char pad0[0x14];
    char sub14[0x14];
    s32 handles[2];
    char pad30[4];
    Src srcs[2];
    char pad27C[0x2B8 - 0x27C];
    char sub2B8[0x2CC - 0x2B8];
    s32 h2CC;
    char pad2D0[4];
    s32 src2D4;
    char pad2D8[0x3F4 - 0x2D8];
    char sub3F4[0x468 - 0x3F4];
    f32 f468[3];
    char pad474[0xB38 - 0x474];
    s32 inited;
};

/* Clears n floats from the last one down. The forward counter with a
 * separate down-counting index lets loop.c emit the counter and pointer
 * inits after the hoisted 0.0f, as retail orders them. */
static inline void zero(f32 *p, int n) {
    f32 t;
    int i;
    int j;
    for (i = 0, j = n - 1; i < n; i++, j--) p[j] = t = 0.0f;
}

static inline void zeroAt(int base, int a, int b, int n) {
    f32 t;
    int i;
    f32 *q;
    for (i = n - 1, q = (f32 *)((a + b) + base); i >= 0; i--) *q-- = t = 0.0f;
}

extern "C" void func_003924D0(Self *s) {
    int i;
    if (s->inited) return;
    s->inited = 1;
    func_00391EB0(s->sub14);
    for (i = 0; i < 2; i++) {
        s->handles[i] = func_00559808();
        func_00559470(s->handles[i], s->srcs[i].x, 0, 0);
        func_00559330(s->handles[i]);
    }
    func_00391EB0(s->sub2B8);
    s->h2CC = func_00559808();
    func_00559470(s->h2CC, s->src2D4, 0, 0);
    func_00559330(s->h2CC);
    func_00391EB0(s->sub3F4);
    zero(s->f468, 3);
    {
        int n;
        char *g;
        int b;
        int a;
        n = 0;
        g = (char *)s + 0x474;
        b = 0x5E8;
        a = 0x28;
        for (; n < 4; n++) {
            func_00391EB0(g);
            zeroAt((int)s, a, b, 11);
            g += 0x1A0;
            b += 0xA0;
            a += 0x100;
        }
    }
}
