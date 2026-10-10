typedef int s32;
typedef float f32;

struct Target {
    char pad0[0x50];
    f32 value;
};

struct Handle {
    Target *obj;
    char pad4[0xC];
};

struct Val {
    s32 v;
    char pad4[0xC];
};

extern "C" void func_00151888(Handle *h);
extern "C" void func_00151830(Handle *h, s32 flags);
extern "C" void func_002F7BC0(Val *v, s32 src);
extern "C" f32 func_002F9158(s32 v);
extern "C" void func_002F7B68(Val *v, s32 flags);

extern "C" void MCarModel__set_alpha(s32 a0, s32 a1, s32 a2, s32 argv) {
    Handle h;
    func_00151888(&h);
    Target *t = h.obj;
    {
        Val v;
        Val *pv = &v;
        func_002F7BC0(pv, argv);
        t->value = func_002F9158(pv->v);
        func_002F7B68(pv, 2);
    }
    func_00151830(&h, 2);
}
