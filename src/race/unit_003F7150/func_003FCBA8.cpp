typedef int s32;

struct Obj {
    char pad0[0x18];
    s32 unk18;
};

extern "C" s32 func_00366678(s32 arg0);

extern "C" s32 func_003FCBA8(Obj *arg0) {
    return func_00366678(arg0->unk18) == 3;
}
