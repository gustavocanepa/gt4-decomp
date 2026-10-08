typedef int s32;

struct Obj {
    char pad0[0x1E0];
    s32 unk1E0;
};

extern "C" s32 func_00449CD8(s32 arg0);

extern "C" s32 func_00603430(Obj *arg0) {
    return func_00449CD8(arg0->unk1E0);
}
