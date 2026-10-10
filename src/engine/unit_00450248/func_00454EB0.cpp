typedef int s32;

struct Obj {
    char pad0[0x18];
    s32 handle;
};

extern "C" Obj *func_00454EF8(void);
extern "C" void func_00499728(Obj *p);
extern "C" void func_0049CE88(s32 h);

extern "C" s32 func_00454EB0(void) {
    Obj *p = func_00454EF8();
    if (p) {
        func_00499728(p);
        func_0049CE88(p->handle);
        return p->handle;
    }
    return 0;
}
