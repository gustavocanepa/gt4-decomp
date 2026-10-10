typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*pfn)(void *self, s32 a);
};

struct Obj_0034D0F8 {
    char pad[0x10140];
    VEntry *vtbl;
};

extern "C" s32 DynamicsConductor__getSpecialStart_Launch(Obj_0034D0F8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    VEntry *e = &arg0->vtbl[36];
    s32 n = e->pfn((char *)arg0 + e->delta, arg1);
    if (n > 0) {
        *arg4 = n;
        return 1;
    }
    return 0;
}
