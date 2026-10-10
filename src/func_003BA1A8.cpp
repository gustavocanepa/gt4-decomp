struct Obj {
    char pad[0xF0F8];
    int ready;
};

extern "C" void func_003EB040(Obj *o, void *x);
extern "C" void func_003EB210(Obj *o, void *x, int a);
extern "C" void func_003EB2A0(Obj *o, int mode, void *x);

extern "C" void func_003BA1A8(Obj *o, int mode, void *x) {
    if (mode == 0) {
        func_003EB040(o, x);
        func_003EB210(o, x, 0);
        o->ready = 1;
    } else {
        func_003EB2A0(o, mode, x);
    }
}
