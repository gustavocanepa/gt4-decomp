/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Lock;
extern "C" void func_00576788(Lock *l);
extern "C" void func_005767C0(Lock *l);

struct Pad {
    unsigned char b0, b1, b2, b3;
};

struct Obj {
    char pad0[0x10];
    char lock[0x70];
    int state;
    unsigned char mode;
    char pad85[0xF];
    int kind;
    unsigned char value[2];
};

extern "C" void func_00552200(Obj *o, Pad *p) {
    func_00576788((Lock *)o->lock);
    unsigned int v = (p->b2 & 1) | (p->b3 << 1);
    o->mode = 3;
    o->value[1] = v >> 8;
    o->kind = 2;
    o->value[0] = v;
    o->state = 1;
    func_005767C0((Lock *)o->lock);
}
