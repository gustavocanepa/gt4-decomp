typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_002C3DF0(s32 arg0);

extern "C" s32 func_0023FB68(Obj *arg0) {
    return func_002C3DF0(arg0->unk14);
}
