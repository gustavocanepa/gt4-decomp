typedef int s32;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_002AE968(void *arg0, int arg1);
extern "C" void func_002AE9C0(void *arg0, void *arg1);
extern "C" void func_002B55E8(char *arg0, s32 arg1, s32 arg2);

extern "C" void func_002B00F0(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    char *h[4];
    if (arg2 == 2) {
        func_002AE9C0(h, arg1);
        {
            char *hv = h[0];
            VObj *o = arg3[0];
            VEntry *e = (VEntry *)(o->vtbl + 0x58);
            s32 a = e->fn((char *)o + e->delta);
            VObj *o2 = arg3[1];
            VEntry *e2 = (VEntry *)(o2->vtbl + 0x58);
            func_002B55E8(hv, a, e2->fn((char *)o2 + e2->delta) != 0);
        }
        func_002AE968(h, 2);
    }
}
