/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj_00109748 {
    char pad0[0x5C];
    bool m5C;
    s32 m60;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
};

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);

extern "C" void GranTurismo4__GameObjectBase__start(Obj_00109748 *o) {
    func_00576788(o);
    bool b = !o->m5C;
    if (b) {
        o->m5C = b;
        o->m60 = 0;
        o->v10();
    }
    func_005767C0(o);
}
