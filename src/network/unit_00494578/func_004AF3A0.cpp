typedef int s32;

struct Obj {
    char pad[0x80];
    s32 state;
    bool done() { return state == 3; }
};

extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005767E0(void *);

extern "C" void func_004AF3A0(Obj *self) {
    func_00576788(self);
    if (!self->done())
        func_005767E0(self);
    func_005767C0(self);
}
