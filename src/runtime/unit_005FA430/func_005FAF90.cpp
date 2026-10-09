typedef int s32;

struct Obj {
    char pad[0x8];
    s32 *unk8;
};

extern "C" s32 func_005FAF90(Obj *arg0, s32 arg1) {
    return arg0->unk8[arg1];
}
