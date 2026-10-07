typedef int s32;

struct UnkStruct {
    char pad[0xC];
    s32 unkC;
};

extern "C" s32 func_00604080(UnkStruct **arg0) {
    return (*arg0)->unkC;
}
