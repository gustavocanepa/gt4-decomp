typedef int s32;

struct Obj { char pad[0x9C]; s32 unk9C; };

extern "C" s32 func_00266338(Obj *arg0) {
    return (arg0->unk9C >> 2) & 1;
}
