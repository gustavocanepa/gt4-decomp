typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x66C - 0x554 - 4];
    f32 unk66C;
    u8 pad2[0x8BC - 0x66C - 4];
    f32 unk8BC;
};

extern "C" f32 func_00344858(Obj *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8BC * temp_f12) + (arg0->unk66C * (1.0f - temp_f12));
}
