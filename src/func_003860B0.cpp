/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct Regs {
    unsigned int w[16];
};

struct Obj {
    Regs *regs;
};

extern "C" void func_003860B0(Obj *o, int which, int v) {
    int i = 12;
    if (which == 0) {
        o->regs->w[i] &= ~0xFF0000;
        o->regs->w[i] |= (u8)v << 16;
    } else {
        o->regs->w[i] &= ~0xFF000000;
        o->regs->w[i] |= (u8)v << 24;
    }
}
