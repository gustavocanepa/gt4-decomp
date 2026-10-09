typedef int s32;

struct UnkStruct {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_00385F60(UnkStruct **arg0) {
    return (*arg0)->unk14;
}
