typedef unsigned char u8;
typedef float f32;

struct Sub00490640 {
    char pad0[0x14];
    u8 unk14;
};

struct S00490640 {
    char pad0[0x14];
    Sub00490640 *unk14;
    char pad1[0x24 - 0x18];
    f32 unk24;
};

extern "C" f32 func_00490640(S00490640 *arg0) {
    f32 temp = (f32)arg0->unk14->unk14;
    return temp * arg0->unk24;
}
