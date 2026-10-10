typedef int s32;

extern "C" void mWidget__getWindowSize(s32 arg0, s32 arg1, s32 arg2);

struct D_Obj {
    char pad[0xC4];
    s32 unkC4;
};

extern "C" void func_002E97E0(D_Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0->unkC4 != 0) {
        mWidget__getWindowSize(arg1, arg2, arg3);
    } else {
        mWidget__getWindowSize(arg1, arg3, arg2);
    }
}
