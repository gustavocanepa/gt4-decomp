typedef int s32;

struct Obj_003F5FF0 {
    char pad0[0x10140];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual s32 v06();
};

extern "C" void func_0034E970(Obj_003F5FF0 *o);
extern "C" void func_003580F8(Obj_003F5FF0 *o);

extern "C" void func_003F5FF0(Obj_003F5FF0 *o) {
    func_0034E970(o);
    if (o->v06()) {
        return func_003580F8(o);
    }
}
