typedef float f32;
typedef unsigned char u8;

struct Obj00344978 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x678 - 0x554 - 4];
    f32 unk678;
    u8 pad2[0x8C8 - 0x678 - 4];
    f32 unk8C8;
};

extern "C" f32 func_00344978(struct Obj00344978 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8C8 * temp_f12) + (arg0->unk678 * (1.0f - temp_f12));
}
