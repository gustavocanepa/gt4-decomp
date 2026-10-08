typedef float f32;
typedef unsigned char u8;

struct Obj00345138 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x700 - 0x554 - 4];
    f32 unk700;
    u8 pad2[0x994 - 0x700 - 4];
    f32 unk994;
};

extern "C" f32 func_00345138(struct Obj00345138 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk994 * temp_f12) + (arg0->unk700 * (1.0f - temp_f12));
}
