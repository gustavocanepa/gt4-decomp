typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mGame__vtable;

struct Obj {
    virtual ~Obj();
};

struct mGame {
    void *vfield;
    void *vptr;
    s32 unk8;
    s32 unkC;
    Obj *p;
    s32 owns;
};

extern "C" void mGame__structor_2(mGame *arg0, s32 arg1) {
    arg0->vptr = &mGame__vtable;
    if (arg0->owns != 0) {
        Obj *t = arg0->p;
        arg0->p = 0;
        delete t;
        arg0->owns = 0;
    }
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
