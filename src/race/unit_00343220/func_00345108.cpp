typedef float f32;
typedef unsigned char u8;

struct Obj00345108 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x8A0 - 0x554 - 4];
    f32 unk8A0;
    u8 pad2[0x990 - 0x8A0 - 4];
    f32 unk990;
};

extern "C" f32 func_00345108(struct Obj00345108 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk990 * temp_f12) + (arg0->unk8A0 * (1.0f - temp_f12));
}
