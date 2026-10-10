typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;
extern void *mStringConst__vtable;

static inline void str_release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

struct hInst__structor_25_arg0 {
    char pad0[0x4];
    void *unk4;
    char *unk8;
};

extern "C" void hInst__structor_25(struct hInst__structor_25_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &mStringConst__vtable;
    str_release(arg0->unk8);
    arg0->unk4 = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
