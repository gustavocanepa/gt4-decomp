typedef float f32;
typedef unsigned char u8;

struct Obj00344948 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x89C - 0x554 - 4];
    f32 unk89C;
    u8 pad2[0x8B8 - 0x89C - 4];
    f32 unk8B8;
};

extern "C" f32 func_00344948(struct Obj00344948 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8B8 * temp_f12) + (arg0->unk89C * (1.0f - temp_f12));
}
