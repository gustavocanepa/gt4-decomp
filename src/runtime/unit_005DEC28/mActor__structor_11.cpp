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

struct HString {
    s32 m0;
    void *vtbl;
    char pad8[8];
    char *p;
};

extern char mActor__vtable[];
extern char D_0069D0E0[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void hObject__structor_2(void *p, s32 flags);

extern "C" void mActor__structor_11(struct HString *self, s32 flags) {
    self->vtbl = mActor__vtable;
    {
        Rep *q = (Rep *)(self->p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    hObject__structor_2(self, 0);
    if (flags & 1) {
        return func_00326798(self, 0x44, 4, D_0069D0E0);
    }
}
