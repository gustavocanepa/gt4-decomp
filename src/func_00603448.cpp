typedef int s32;

struct Obj {
    char pad0[0x1E4];
    s32 unk1E4;
};

extern "C" s32 func_00449CD8(s32 arg0);

extern "C" s32 func_00603448(Obj *arg0) {
    return func_00449CD8(arg0->unk1E4);
}
