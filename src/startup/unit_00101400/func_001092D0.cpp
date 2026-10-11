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

extern "C" s32 func_00575D00(void);
extern "C" s32 malloc(s32);
extern "C" void free(s32);
extern "C" void func_00108EE8(void);

extern "C" void func_001092D0(void) {
    if (D_006186F4 == 0) {
        D_006186F4 = 1;
        s32 r = malloc(func_00575D00() - 0x100000);
        func_00108EE8();
        Obj *o = D_006186F8;
        VEntry *e = (VEntry *)(o->vtbl + 0x10);
        e->fn((char *)o + e->delta);
        free(r);
    }
}
