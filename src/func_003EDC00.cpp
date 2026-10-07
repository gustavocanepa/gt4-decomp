typedef int s32;

struct Obj {
    char pad0[0x12C];
    void *unk12C;
    char unk130[1];
};

extern void *D_00684B48;
extern "C" void func_00444210(void *, s32);
extern "C" void func_003BB3D8(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_003EDC00(struct Obj *arg0, s32 arg1)
{
    arg0->unk12C = &D_00684B48;
    func_00444210(&arg0->unk130, 2);
    func_003BB3D8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
