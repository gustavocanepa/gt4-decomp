typedef int s32;

struct UnkStruct385F20 {
    char pad[0x28];
    s32 unk28;
};

extern "C" s32 func_00385F20(UnkStruct385F20 **arg0) {
    return (*arg0)->unk28;
}
