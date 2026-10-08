typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0054C748(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_00276918(struct Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_0054C748(arg0->unk10 - 1, arg1, arg2, arg3, 0);
}
