typedef short s16;
typedef int s32;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 pad;
    f32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_00255110(s32 *buf);
extern "C" void mWidget__setWindowH(s32 arg0, f32 arg1);
extern "C" void func_002550B8(s32 *buf, s32 arg1);

extern "C" void MWidget__set_h(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    s32 s1;
    ObjA *obj;
    VEntry *entry;
    f32 result;

    func_00255110(buf);
    s1 = buf[0];
    obj = arg3->obj;
    entry = obj->vtbl + 12;
    result = entry->fn((char *)obj + entry->delta);
    mWidget__setWindowH(s1, result);
    func_002550B8(buf, 2);
}
