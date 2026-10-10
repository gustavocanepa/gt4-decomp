typedef int s32;
typedef unsigned char u8;

struct S003A9738 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};

extern "C" void Oscillator__setCount(struct S003A9738 *arg0, s32 arg1, u8 arg2) {
    arg0->unk18 = arg1;
    arg0->unk1C = (arg0->unk1C & ~0xFF) | arg2;
}
