typedef int s32;

struct UnkStruct {
    char pad[0x18];
    s32 unk18;
};

extern "C" s32 func_00385F00(UnkStruct **arg0) {
    return (*arg0)->unk18;
}
