typedef float f32;
typedef unsigned char u8;

struct Obj00344918 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x898 - 0x554 - 4];
    f32 unk898;
    u8 pad2[0x8B4 - 0x898 - 4];
    f32 unk8B4;
};

extern "C" f32 func_00344918(struct Obj00344918 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8B4 * temp_f12) + (arg0->unk898 * (1.0f - temp_f12));
}
