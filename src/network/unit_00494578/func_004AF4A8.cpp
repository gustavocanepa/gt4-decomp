struct Obj;
extern "C" void func_00576788(Obj *o);
extern "C" void func_005767C0(Obj *o);
extern "C" void func_00576968(Obj *o);
extern "C" void func_004AED70(void *p, Obj *o);
extern "C" void func_004AF568(Obj *o);

struct Obj {
    char pad0[0x50];
    void *m50;
    char pad54[0x60 - 0x54];
    void *m60;
    char pad64[0x80 - 0x64];
    int state;
};

extern "C" void func_004AF4A8(Obj *o) {
    func_00576788(o);
    bool b = o->state != 3;
    if (b) {
        o->state = 3;
        func_00576968(o);
    }
    if (o->m50)
        func_004AED70(o->m50, o);
    void *p = o->m60;
    func_005767C0(o);
    if (p)
        func_004AF568(o);
}
