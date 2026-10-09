typedef int s32;

struct UnkStruct {
    char pad[0x8];
    s32 unk8;
};

extern "C" s32 func_00386630(UnkStruct **arg0) {
    return (*arg0)->unk8;
}
