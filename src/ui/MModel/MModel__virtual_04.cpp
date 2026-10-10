typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct VObj {
    s32 unk0;
    char *vtbl;
};

extern "C" VObj *func_0021A7D8(void *);

extern "C" void MModel__virtual_04(void *arg0, s32 arg1) {
    VObj *o = func_0021A7D8(arg0);
    VEntry *e = (VEntry *)(o->vtbl + 0x50);
    e->fn((char *)o + e->delta, arg1);
}
