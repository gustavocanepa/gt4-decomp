typedef int s32;

struct Obj_00476558;

struct Owner_00476558 {
    char pad0[0x5C];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual s32 v06(Obj_00476558 *o, s32 n);
};

struct Obj_00476558 {
    Owner_00476558 *m0;
    char pad4[0x3C];
    char m40[4];
};

extern "C" void func_0047CFD8(void *p, s32 n);

extern "C" s32 func_00476558(Obj_00476558 *arg0) {
    func_0047CFD8(arg0->m40, 0);
    if (arg0->m0 != 0) {
        return arg0->m0->v06(arg0, 0x20);
    }
    return 0;
}
