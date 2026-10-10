typedef int s32;

extern "C" void func_003286B8(s32 arg0);
extern "C" void func_0030F808(void *arg0, s32 arg1);
extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;
extern void *mModuleDefine__vtable;

struct hInst__structor_18_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x10];
    s32 unk18;
};

extern "C" void hInst__structor_18(void *arg0, s32 arg1) {
    s32 p;
    ((struct hInst__structor_18_arg0 *)arg0)->unk4 = &mModuleDefine__vtable;
    p = ((struct hInst__structor_18_arg0 *)arg0)->unk18;
    if (p != 0) {
        func_003286B8(p);
    }
    func_0030F808((char *)arg0 + 8, 2);
    ((struct hInst__structor_18_arg0 *)arg0)->unk4 = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x1C, 4, "RefCounter");
    }
}
