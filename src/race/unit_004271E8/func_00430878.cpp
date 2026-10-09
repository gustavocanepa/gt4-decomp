typedef int s32;

struct Obj { char pad[0x4C]; s32 unk4C; };

extern "C" s32 func_00430878(Obj *arg0) {
    return arg0->unk4C & 1;
}
