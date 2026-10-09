typedef int s32;

extern void *mWindowContext__vtable;
extern "C" void func_005DECE0(void *, void *);
extern "C" void *func_005DF780(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void hObject__structor_2(void *, s32);
static inline void member_0(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005DECE0(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
    void *p0 = *(void **)(m + 0x4);
    void *r1 = func_005DF780();
    func_00326798(p0, 0x18, 0x4, *(void **)(r1));
}

extern "C" void mWindowContext__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mWindowContext__vtable;
    member_0((char *)arg0 + 0x20);
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x34, 0x4, "RefCounter");
    }
}
