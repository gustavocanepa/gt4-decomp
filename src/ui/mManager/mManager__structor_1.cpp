typedef int s32;

extern void *mManager__vtable;
extern "C" void func_005D8B18(void *, void *);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_0024E378(void *, s32);
extern "C" void *func_005D9F58(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void hObject__structor_2(void *, s32);
static inline void member_0(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005D8B18(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
}
static inline void member_1(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005D8B18(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
    void *p0 = *(void **)(m + 0x4);
    void *r4 = func_005D9F58();
    func_00326798(p0, 0x18, 0x4, *(void **)(r4));
}

extern "C" void mManager__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mManager__vtable;
    member_0((char *)arg0 + 0x10);
    func_003041B8((char *)arg0 + 0x24, 0x2);
    func_0024E378((char *)arg0 + 0x20, 0x2);
    member_1((char *)arg0 + 0x10);
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x30, 0x4, "RefCounter");
    }
}
