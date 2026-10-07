typedef int s32;

struct Obj {
    char pad[0x16B0];
    s32 unk16B0;
};

extern "C" s32 func_004373F0(Obj *arg0) {
    return *(s32 *)(0x622DF0 + (arg0->unk16B0 * 4));
}
