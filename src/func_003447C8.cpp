typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x5A8 - 0x554 - 4];
    f32 unk5A8;
    u8 pad2[0x99C - 0x5A8 - 4];
    f32 unk99C;
};

extern "C" f32 func_003447C8(Obj *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk99C * temp_f12) + (arg0->unk5A8 * (1.0f - temp_f12));
}
