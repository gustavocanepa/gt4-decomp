typedef float f32;
typedef char s8;

struct Obj {
    char pad[0x78D];
    s8 unk78D;
};

extern "C" f32 func_00355DA8(Obj *arg0) {
    f32 var_f0 = 1.0f;
    if (arg0->unk78D < 0) {
        var_f0 = 0.0f;
    }
    return var_f0;
}
