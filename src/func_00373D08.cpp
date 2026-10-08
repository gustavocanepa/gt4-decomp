typedef int s32;

struct Base_00373D08 {
    char pad0[0x144];
    s32 unk144;
};

struct Shifted_00373D08 {
    char pad0[0x128];
    s32 unk128;
    char pad1[0x134 - 0x128 - 4];
    s32 unk134;
};

extern "C" s32 func_00373D08(char *arg0, s32 arg1) {
    Base_00373D08 *base = (Base_00373D08 *)(arg0 + arg1 * 0x19C);
    Shifted_00373D08 *e = (Shifted_00373D08 *)((char *)base + 0x10);
    s32 var_v0;

    var_v0 = e->unk128;
    if ((base->unk144 ^ 9) != 0) {
        var_v0 = e->unk134;
    }
    return var_v0;
}
