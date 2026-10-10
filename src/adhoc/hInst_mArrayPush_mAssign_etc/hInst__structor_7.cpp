typedef int s32;

extern "C" void func_003286B8(s32 arg0);
extern "C" void func_0030F808(void *arg0, s32 arg1);
extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;
extern void *mClassDefine__vtable;

struct hInst__structor_7_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x14];
    s32 unk1C;
};

extern "C" void hInst__structor_7(void *arg0, s32 arg1) {
    s32 p;
    ((struct hInst__structor_7_arg0 *)arg0)->unk4 = &mClassDefine__vtable;
    p = ((struct hInst__structor_7_arg0 *)arg0)->unk1C;
    if (p != 0) {
        func_003286B8(p);
    }
    func_0030F808((char *)arg0 + 0xC, 2);
    ((struct hInst__structor_7_arg0 *)arg0)->unk4 = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x20, 4, "RefCounter");
    }
}
