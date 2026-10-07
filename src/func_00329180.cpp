typedef int s32;
typedef unsigned int u32;

struct VEntry1 {
    short delta;
    short pad;
    s32 (*fn)(void *, s32);
};

struct VEntry2 {
    short delta;
    short pad;
    s32 (*fn)(void *);
};

extern "C" void func_00328A00(s32 arg0);

extern "C" void func_00329180(void **arg0) {
    s32 i;
    for (i = 0; ; i++) {
        VEntry2 *e2 = (VEntry2 *)((char *)*arg0 + 0x18);
        s32 count = e2->fn((char *)arg0 + e2->delta);
        if (!((u32)i < (u32)count)) {
            break;
        }
        VEntry1 *e1 = (VEntry1 *)((char *)*arg0 + 0x10);
        func_00328A00(e1->fn((char *)arg0 + e1->delta, i));
    }
}
