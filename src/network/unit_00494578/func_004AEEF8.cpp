struct Obj {
    char pad0[0xAC];
    int pending;
};

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_004AF3A0(Obj *o);

extern "C" void func_004AEEF8(Obj *o) {
    func_00576788(o);
    bool idle = o->pending == 0;
    func_005767C0(o);
    if (!idle) {
        func_004AF3A0(o);
    }
}
