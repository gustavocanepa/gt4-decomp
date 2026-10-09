typedef int s32;

struct Obj {
    char pad[0x3C];
    s32 *unk3C;
};

extern "C" s32 func_004552E8(Obj *arg0, s32 arg1) {
    return arg0->unk3C[arg1];
}
