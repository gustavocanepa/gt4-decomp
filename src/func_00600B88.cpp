typedef int s32;

struct S_00600B88 {
    char pad0[0xB6C4];
    s32 unkB6C4;
};

extern "C" s32 func_00600B88(struct S_00600B88 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkB6C4;
    arg0->unkB6C4 = 0;
    return temp_v0;
}
