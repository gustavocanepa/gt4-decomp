typedef float f32;
typedef unsigned char u8;

struct Obj {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x890 - 0x554 - 4];
    f32 unk890;
    u8 pad2[0x8AC - 0x890 - 4];
    f32 unk8AC;
};

extern "C" f32 func_00344828(Obj *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8AC * temp_f12) + (arg0->unk890 * (1.0f - temp_f12));
}
