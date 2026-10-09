typedef int s32;

extern void *mUpdateContextPS2__vtable;
extern "C" void func_005D90F8(void *, void *);
extern "C" void *func_005DA140(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_00105280(void *, s32);
extern "C" void func_0055FA30(void *, s32);
extern "C" void func_00574DA8(void *, s32);
extern "C" void mUpdateContext__structor_1(void *, s32);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0xd0) + 0x8);
    e->fn(o + e->delta, a0);
}
static inline void member_0(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005D90F8(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
    void *p0 = *(void **)(m + 0x4);
    void *r1 = func_005DA140();
    func_00326798(p0, 0x1c, 0x4, *(void **)(r1));
}

extern "C" void mUpdateContextPS2__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mUpdateContextPS2__vtable;
    member_0((char *)arg0 + 0x424);
    func_00105280((char *)arg0 + 0x3e4, 0x2);
    if ((char *)arg0 + 0x1a0 != 0) {
        char *p1 = (char *)arg0 + 0x348;
        while ((char *)arg0 + 0x1a0 != p1) {
            p1 -= 0xd4;
            vcall_0(p1, 0x2);
        }
    }
    func_0055FA30((char *)arg0 + 0x160, 0x2);
    func_00574DA8((char *)arg0 + 0x130, 0x2);
    mUpdateContext__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x434, 0x4, "RefCounter");
    }
}
