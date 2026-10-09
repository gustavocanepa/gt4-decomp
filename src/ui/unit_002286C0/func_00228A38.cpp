typedef float f32;

struct Obj00228A38 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

extern "C" f32 func_00228A38(struct Obj00228A38 *arg0) {
    f32 temp_f2 = arg0->unk10;
    f32 temp_f1 = arg0->unk14;
    f32 var_f0 = 1.0f;

    if (temp_f1 != temp_f2) {
        var_f0 = (arg0->unk18 - temp_f2) / (temp_f1 - temp_f2);
    }
    return var_f0;
}
