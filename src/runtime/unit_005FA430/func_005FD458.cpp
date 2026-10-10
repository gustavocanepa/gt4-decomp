typedef int s32;

struct Obj {
    char pad0[0x80];
    s32 unk80;
    char pad84[0x24];
    s32 unkA8;
    s32 unkAC;
};

extern "C" Obj *func_005FCAA0(void *);

extern "C" Obj *func_005FD458(void *self, s32 a, s32 b) {
    Obj *p = func_005FCAA0(self);
    if (p != 0) {
        p->unkAC = b;
        p->unkA8 = a;
        p->unk80 = 0;
    }
    return p;
}
