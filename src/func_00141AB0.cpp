typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg2 {
    char pad0[4];
    ObjA *obj;
};

extern "C" void func_002ED618(void *buf, Arg2 *arg2);
extern "C" void func_00146E88(void *buf, s32 flag);

extern "C" void func_00141AB0(void *arg0, s32 count, Arg2 *arg2) {
    char buf[0x10];
    s32 flag;

    if (count <= 0) {
        return;
    }
    func_002ED618(buf, arg2);
    flag = 1;
    if (count >= 2) {
        ObjA *obj = arg2->obj;
        VEntry *entry = obj->vtbl + 11;
        s32 result = entry->fn((char *)obj + entry->delta);
        flag = (result != 0);
    }
    func_00146E88(buf, flag);
}
