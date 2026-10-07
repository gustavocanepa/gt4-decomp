typedef float f32;
typedef unsigned char u8;

struct Inner00355950 {
    char pad0[0x32];
    u8 unk32;
};

struct Obj00355950 {
    char pad0[0x10];
    Inner00355950 *unk10;
    char pad14[0x78C - 0x14];
    f32 unk78C;
};

extern "C" f32 func_00355950(struct Obj00355950 *arg0) {
    f32 var_f0;

    var_f0 = 0.0f;
    if (arg0->unk10->unk32 == 3) {
        var_f0 = arg0->unk78C;
    }
    return var_f0;
}
