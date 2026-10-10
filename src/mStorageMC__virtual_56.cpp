typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0054C768(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 mStorageMC__virtual_56(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 spare[4];
    s32 r = func_0054C768(arg0->unk10 - 1, arg1, arg2, arg3, 0);
    spare[0] = r;
    if (r != 0) {
        arg3 = -r;
    }
    return arg3;
}
