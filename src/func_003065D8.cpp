typedef int s32;

struct UnkStruct {
    char pad[0x8];
    s32 unk8;
};

struct Obj {
    char pad[0x1C];
    UnkStruct *unk1C;
};

extern "C" s32 func_003065D8(Obj *arg0) {
    return arg0->unk1C->unk8;
}
