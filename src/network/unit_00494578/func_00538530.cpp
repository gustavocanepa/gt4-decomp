typedef int s32;

struct Obj {
    char pad[0xC];
    s32 unkC;
};

extern "C" s32 func_00538530(Obj *arg0, s32 *arg1) {
    if (arg0 == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    *arg1 = arg0->unkC;
    return 0;
}
