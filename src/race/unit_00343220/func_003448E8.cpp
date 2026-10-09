typedef float f32;
typedef unsigned char u8;

struct Obj003448E8 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x894 - 0x554 - 4];
    f32 unk894;
    u8 pad2[0x8B0 - 0x894 - 4];
    f32 unk8B0;
};

extern "C" f32 func_003448E8(struct Obj003448E8 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8B0 * temp_f12) + (arg0->unk894 * (1.0f - temp_f12));
}
