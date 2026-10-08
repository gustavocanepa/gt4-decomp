typedef float f32;
typedef unsigned char u8;

struct Obj003449A8 {
    u8 pad0[0x554];
    f32 unk554;
    u8 pad1[0x67C - 0x554 - 4];
    f32 unk67C;
    u8 pad2[0x8CC - 0x67C - 4];
    f32 unk8CC;
};

extern "C" f32 func_003449A8(struct Obj003449A8 *arg0, f32 fparg0) {
    f32 temp_f12 = fparg0 + arg0->unk554;
    return (arg0->unk8CC * temp_f12) + (arg0->unk67C * (1.0f - temp_f12));
}
