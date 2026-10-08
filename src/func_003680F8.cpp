typedef unsigned char u8;
typedef float f32;

struct Sub_003680F8 {
    char pad0[0x247];
    u8 unk247;
};

struct Struct_003680F8 {
    char pad0[0x10];
    Sub_003680F8 *unk10;
};

extern "C" f32 func_003680F8(Struct_003680F8 *arg0) {
    f32 var_f0;

    var_f0 = 500.0f;
    if (arg0->unk10->unk247 != 3) {
        var_f0 = 274.0f;
    }
    return var_f0;
}
