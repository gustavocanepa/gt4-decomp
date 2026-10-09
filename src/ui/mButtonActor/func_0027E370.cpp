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
extern "C" void func_0027E120(void *arg0, int arg1);
extern "C" void func_0027E178(void *arg0, void *arg1);
extern "C" void func_0027E748(Obj *arg0, void *arg1);

extern "C" void func_0027E370(void *arg0, void *arg1, s32 n, void *arg3) {
    if (n > 0) {
        OHandle h0;
        Handle b;
        Handle *pb;
        func_0027E178(&h0, arg1);
        pb = &b;
        func_00204D88(pb, arg3);
        {
            Obj *o = h0.p;
            VEntry *e = (VEntry *)(o->vtbl + 0x190);
            e->fn((char *)o + e->delta);
        }
        func_0027E748(h0.p, pb->p);
        func_00204D30(pb, 2);
        func_0027E120(&h0, 2);
    }
}
