typedef int s32;

struct Obj_0044D220 {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual s32 v08();
};

extern "C" void func_0044D2A8(void *p);

extern "C" s32 func_0044D220(Obj_0044D220 *arg0, void *arg1) {
    s32 r = arg0->v08();
    func_0044D2A8(arg1);
    return r;
}
