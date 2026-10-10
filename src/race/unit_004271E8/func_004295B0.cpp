typedef int s32;

struct Listener_004295B0 {
    virtual void v01(void *e);
};

struct Obj_004295B0 {
    char pad0[8];
    void *m8;
    Listener_004295B0 *mC;
};

extern "C" s32 ModelSet2__searchModelName(void *a, void *e, s32 n);

extern "C" void func_004295B0(Obj_004295B0 *o, void *e) {
    if (ModelSet2__searchModelName(o->m8, e, 0)) {
        o->mC->v01(e);
    }
}
