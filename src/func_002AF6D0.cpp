typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_002AE9C0(s32 *buf);
extern "C" void func_002B4A00(s32 arg0, s32 arg1);
extern "C" void func_002AE968(s32 *buf, s32 arg1);

extern "C" void func_002AF6D0(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    s32 s0;
    ObjA *obj;
    VEntry *entry;
    s32 result;

    if (arg2 == 1) {
        func_002AE9C0(buf);
        s0 = buf[0];
        obj = arg3->obj;
        entry = obj->vtbl + 11;
        result = entry->fn((char *)obj + entry->delta);
        func_002B4A00(s0, result);
        func_002AE968(buf, 2);
    }
}
