typedef int s32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct OHandle {
    Obj *p;
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_00204D30(void *arg0, int arg1);
extern "C" void func_00204D88(void *arg0, void *arg1);
extern "C" void func_002E1FE0(void *arg0, int arg1);
extern "C" void func_002E2038(void *arg0, void *arg1);
extern "C" void func_002E2908(Obj *arg0, void *arg1);

extern "C" void MSwitchActor__global_0083B4E8(void *arg0, void *arg1, s32 n, void *arg3) {
    if (n > 0) {
        OHandle h0;
        Handle b;
        Handle *pb;
        func_002E2038(&h0, arg1);
        pb = &b;
        func_00204D88(pb, arg3);
        {
            Obj *o = h0.p;
            VEntry *e = (VEntry *)(o->vtbl + 0x190);
            e->fn((char *)o + e->delta);
        }
        func_002E2908(h0.p, pb->p);
        func_00204D30(pb, 2);
        func_002E1FE0(&h0, 2);
    }
}
