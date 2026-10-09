typedef int s32;

struct S002314E8 {
    char pad0[0x1D00];
    s32 unk1D00;
};

extern "C" char *func_002314E8(struct S002314E8 *arg0) {
    return (char *)arg0 + (arg0->unk1D00 * 0x38) + 0x730;
}
