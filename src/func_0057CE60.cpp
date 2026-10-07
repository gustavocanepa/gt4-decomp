typedef int s32;

struct Obj { char pad[4]; s32 unk4; s32 unk8; };

extern "C" s32 func_0057CE60(Obj *arg0) {
    return arg0->unk8 - arg0->unk4;
}
