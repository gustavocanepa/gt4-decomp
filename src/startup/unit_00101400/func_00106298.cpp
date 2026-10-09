typedef int s32;

struct Obj {
    char pad0[0x78];
    s32 unk78;
};

extern "C" s32 func_00106298(char *arg0) {
    arg0 = arg0 + 0xB8;
    arg0 = arg0 + (((Obj *)arg0)->unk78 * 0x3C);
    return *(s32 *)(arg0 + 0x8);
}
