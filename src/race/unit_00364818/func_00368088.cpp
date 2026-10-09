typedef float f32;

struct Sub {
    char pad[0x247];
    unsigned char unk247;
};

struct S00368088 {
    char pad[0x10];
    Sub *unk10;
};

extern "C" f32 func_00368088(S00368088 *arg0) {
    f32 var_f0 = 1047.1974f;
    if (arg0->unk10->unk247 != 3) {
        var_f0 = 680.6783f;
    }
    return var_f0;
}
