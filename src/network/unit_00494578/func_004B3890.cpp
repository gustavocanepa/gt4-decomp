typedef int s32;

struct Obj { char pad[0x4]; s32 unk4; s32 unk8; };

extern "C" s32 func_004B3890(Obj *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    return temp_v0;
}
