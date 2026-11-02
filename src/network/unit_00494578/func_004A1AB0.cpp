/* Switches the scratchpad's address mode (0, 1 = 0x2..., 2 = 0x3...) and rebases its three saved
   pointers onto the new base; leaving mode 0 syncs and calls func_005ADF20(0). Case 0's plain
   (non-volatile) store is what lets reorg steal it into the branch's likely slot, as in retail. */
#include "spr.h"
struct Spr {
    char pad0[0x1F8];
    unsigned int p1F8;
    unsigned int p1FC;
    int mode;
    unsigned int base;
    unsigned int p208;
    char pad20C[0x2C2 - 0x20C];
    unsigned char fix;
};
extern "C" void func_005ADF20(int);

static inline unsigned int fix(volatile Spr *spr, unsigned int p) {
    unsigned int v = 0;
    if (p == 0)
        return v;
    v = (p & 0x0FFFFFFF) | spr->base;
    return v;
}

extern "C" void func_004A1AB0(unsigned int mode) {
    volatile struct Spr *spr = (volatile struct Spr *)spr_base();
    unsigned int old = spr->mode;
    unsigned int b;
    if (old == mode)
        return;
    switch (mode) {
    case 1:
        b = 0x20000000;
        break;
    case 2:
        b = 0x30000000;
        break;
    case 0:
        ((Spr *)spr)->base = 0;
        goto done;
    default:
        return;
    }
    spr->base = b;
done:
    if (!spr->fix)
        return;
    spr->p1F8 = fix(spr, spr->p1F8);
    do { spr->p1FC = fix(spr, spr->p1FC); } while (0);
    do { spr->p208 = fix(spr, spr->p208); } while (0);
    if (old == 0) {
        __asm__ volatile("sync");
        func_005ADF20(0);
    }
    spr->mode = mode;
}
