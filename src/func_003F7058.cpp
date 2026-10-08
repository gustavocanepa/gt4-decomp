typedef int s32;

struct Obj {
    char pad0[0xF864];
    char unkF864;
};

extern "C" s32 func_0034CA20(Obj *arg0);

extern "C" s32 func_003F7058(Obj *arg0) {
    arg0->unkF864 = 0;
    return func_0034CA20(arg0);
}
