typedef int s32;

struct Obj {
    char pad[0xA0];
    s32 unkA0;
};

extern "C" s32 func_001CA9B0(s32 arg0);

extern "C" s32 func_0019A850(Obj *arg0) {
    return func_001CA9B0(arg0->unkA0);
}
