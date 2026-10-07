typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_00463840(Obj *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    return temp_v0;
}
