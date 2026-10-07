typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0x5B8 - 4];
    s32 unk5B8;
    s32 unk5BC;
};

extern "C" s32 func_00450AD0(Obj *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk0;
    arg0->unk0 = 0;
    arg0->unk5B8 = 0;
    arg0->unk5BC = 0;
    return temp_v0;
}
