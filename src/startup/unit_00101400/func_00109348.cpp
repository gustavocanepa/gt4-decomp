typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x64];
    char *vtbl;
};

extern s32 D_006186F4;
extern Obj *D_006186F8;

extern "C" void func_00108F38(void);

extern "C" void func_00109348(void) {
    if (D_006186F4 != 0) {
        D_006186F4 = 0;
        Obj *o = D_006186F8;
        VEntry *e = (VEntry *)(o->vtbl + 0x20);
        e->fn((char *)o + e->delta);
        func_00108F38();
    }
}
