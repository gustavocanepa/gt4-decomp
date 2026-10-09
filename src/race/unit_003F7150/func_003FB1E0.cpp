typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

struct Pad {
    char pad0[4];
    char *dev;
    char pad8[4];
    s32 held;
    s32 trig;
    s32 port;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w24;
};

extern "C" s32 func_003FAB98(s32);
extern "C" s32 func_00426A90(char *);
extern "C" s32 func_00426A88(char *);

extern "C" void func_003FB1E0(Pad *p) {
    char *dev = p->dev;
    s32 busy;
    s32 trig;
    s32 held;

    p->port = *(s32 *)(dev + 0x1C4);
    busy = func_003FAB98(p->port);
    trig = func_00426A90(dev);
    held = func_00426A88(dev);
    p->trig = trig;
    p->held = held;
    if (held & 1) {
        p->w18 = (p->w18 & ~0xFF) | 1;
    }
    if (held & 0x4000) {
        p->w18 = (p->w18 & 0xFF00FFFF) | 0x10000;
    }
    if (held & 0x8000) {
        p->w18 = (p->w18 & 0xFFFFFF) | 0x1000000;
    }
    if (held & 0x10000) {
        p->w1c = (p->w1c & ~0xFF) | 1;
    }
    if (held & 0x20000) {
        p->w1c = (p->w1c & 0xFFFF00FF) | 0x100;
    }
    if (busy != 0) {
        if (trig & 2) {
            ((s8 *)p)[0x19] = 1;
        }
    } else {
        if (trig & 2) {
            ((s8 *)p)[0x19] = 1;
        }
        if (trig & 1) {
            p->w20 = (p->w20 & 0xFFFF00FF) | 0x100;
        }
        if (held & 0x80) {
            ((s8 *)p)[0x22]--;
        }
        if (held & 0x100) {
            ((s8 *)p)[0x22]++;
        }
        if (trig & 0x200) {
            ((s8 *)p)[0x23]--;
        }
        if (trig & 0x400) {
            ((s8 *)p)[0x23]++;
        }
    }
    if (busy == 0) {
        if (trig & 8) {
            ((s8 *)p)[0x1F] = 1;
        }
        if (trig & 4) {
            ((s8 *)p)[0x1F] = -1;
        }
    }
    if (trig & 0x10) {
        p->w20 = (p->w20 & ~0xFF) | 1;
    }
    if (trig & 0x2000) {
        p->w24 = (p->w24 & ~0xFF) | 1;
    }
    if (busy == 0 && (held & 0x20)) {
        p->w1c = (p->w1c & 0xFF00FFFF) | 0x10000;
    }
}
