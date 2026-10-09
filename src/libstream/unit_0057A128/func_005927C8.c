typedef int s32; typedef unsigned char u8; typedef unsigned long long u64;

struct Ios {
    s32 pad0;
    s32 tie;
    s32 pad8[2];
    long flags;
    u8 pad18[2];
    u8 state;
};

void func_00592418(struct Ios **, u64, s32);
void func_00593020(s32);

struct Ios **func_005927C8(struct Ios **self, int n) {
    s32 ok;
    struct Ios *ios;
    s32 t;

    ios = *self;
    ok = 0;
    if (ios->state == 0) {
        t = ios->tie;
        if (t != 0) {
            func_00593020(t);
        }
        ok = 1;
    }
    if (ok != 0) {
        s32 sgn = 1;
        unsigned mag = (unsigned)n;
        if (n < 0 && ((*self)->flags & 0x60) == 0)
            mag = -((unsigned)n), sgn = -1;
        func_00592418(self, mag, sgn);
    }
    return self;
}
