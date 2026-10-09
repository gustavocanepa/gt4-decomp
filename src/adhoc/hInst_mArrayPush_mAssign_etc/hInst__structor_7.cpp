typedef int s32;

extern "C" void func_003286B8(s32 arg0);
extern "C" void func_0030F808(void *arg0, s32 arg1);
extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;
extern void *mClassDefine__vtable;

extern "C" void hInst__structor_7(void *arg0, s32 arg1) {
    s32 p;
    *(void **)((char *)arg0 + 4) = &mClassDefine__vtable;
    p = *(s32 *)((char *)arg0 + 0x1C);
    if (p != 0) {
        func_003286B8(p);
    }
    func_0030F808((char *)arg0 + 0xC, 2);
    *(void **)((char *)arg0 + 4) = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x20, 4, "RefCounter");
    }
}
