typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x88C - 0x554 - 4];
    f32 unk88C;
    u8 pad2[0x8A8 - 0x88C - 4];
    f32 unk8A8;
};

extern "C" f32 func_003447F8(Obj *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8A8 * temp_f12) + (arg0->unk88C * (1.0f - temp_f12));
}
