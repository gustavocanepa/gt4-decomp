typedef int s32;

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" s32 func_00447730(s32 arg0);

extern "C" s32 func_005FBB20(Obj *arg0) {
    return func_00447730(arg0->unk70);
}
