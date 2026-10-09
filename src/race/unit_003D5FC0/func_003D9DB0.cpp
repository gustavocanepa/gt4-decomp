typedef int s32;

struct Obj {
    char pad[0x4C];
    s32 unk4C;
};

extern "C" s32 func_003D9D28(struct Obj *arg0, s32 arg1);

extern "C" s32 func_003D9DB0(struct Obj *arg0) {
    s32 v = arg0->unk4C - 1;
    if (v < 0) v = 0;
    return func_003D9D28(arg0, v);
}
