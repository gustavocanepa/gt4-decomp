typedef float f32;

struct S0047DB98 {
    char pad[0x2C];
    f32 unk2C;
};

extern "C" f32 func_0047DB98(S0047DB98 *arg0) {
    return arg0->unk2C * 0x1.ca5dc2p+5f;
}
