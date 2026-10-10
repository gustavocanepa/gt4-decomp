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

extern "C" void DynamicsConductor__terminate(Obj_003F5FF0 *o);
extern "C" void DynamicsConductor__updateSolitaire_atTermination(Obj_003F5FF0 *o);

extern "C" void DynamicsConductorLicense__terminate(Obj_003F5FF0 *o) {
    DynamicsConductor__terminate(o);
    if (o->v06()) {
        return DynamicsConductor__updateSolitaire_atTermination(o);
    }
}
