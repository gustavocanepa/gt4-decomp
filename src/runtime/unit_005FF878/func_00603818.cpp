typedef int s32;

struct UnkStruct8 {
    char pad[0x8];
    s32 unk8;
};

struct UnkStructC {
    char pad[0xC];
    s32 unkC;
};

extern "C" s32 func_00603818(struct UnkStruct8 **arg0) {
    return (*arg0)->unk8;
}

extern "C" s32 func_00385F40(struct UnkStructC **arg0) {
    return (*arg0)->unkC;
}
