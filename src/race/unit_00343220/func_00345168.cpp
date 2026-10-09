typedef float f32;
typedef unsigned char u8;

struct Obj00345168 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x704 - 0x554 - 4];
    f32 unk704;
    u8 pad2[0x998 - 0x704 - 4];
    f32 unk998;
};

extern "C" f32 func_00345168(struct Obj00345168 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk998 * temp_f12) + (arg0->unk704 * (1.0f - temp_f12));
}
