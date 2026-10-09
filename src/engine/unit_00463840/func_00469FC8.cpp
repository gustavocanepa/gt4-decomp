typedef int s32;
typedef unsigned char u8;

struct Struct_00469FC8 {
    u8 unk0;
    char pad1[7];
    s32 unk8;
};

s32 func_00469FC8(struct Struct_00469FC8 *arg0, s32 arg1) {
    if (arg0->unk0 != 0) {
        return arg0->unk8 + (arg1 << 6);
    }
    return arg0->unk8 + arg1 * 40;
}
