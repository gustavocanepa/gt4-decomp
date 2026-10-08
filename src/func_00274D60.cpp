typedef int s32;

struct Obj {
    char pad[0x268];
    s32 unk268;
};

extern "C" s32 func_004EE678(s32 arg0);

extern "C" s32 func_00274D60(Obj *arg0) {
    return func_004EE678(arg0->unk268);
}
