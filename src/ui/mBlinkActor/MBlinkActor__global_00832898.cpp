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

extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_00278F38(void *arg0, int arg1);
extern "C" void func_00278F90(void *arg0, void *arg1);
extern "C" void func_002797F8(Obj *arg0, void *arg1);

extern "C" void MBlinkActor__global_00832898(void *arg0, void *arg1, s32 n, void *arg3) {
    if (n > 0) {
        OHandle h0;
        Handle b;
        Handle *pb;
        func_00278F90(&h0, arg1);
        pb = &b;
        func_00255110(pb, arg3);
        {
            Obj *o = h0.p;
            VEntry *e = (VEntry *)(o->vtbl + 0x190);
            e->fn((char *)o + e->delta);
        }
        func_002797F8(h0.p, pb->p);
        func_002550B8(pb, 2);
        func_00278F38(&h0, 2);
    }
}
