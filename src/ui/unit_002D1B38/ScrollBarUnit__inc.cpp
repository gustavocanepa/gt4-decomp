typedef float f32;

struct Obj002D2318 {
    char pad0[0xC];
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

extern "C" void ScrollBarUnit__inc(struct Obj002D2318 *arg0, f32 fparg0) {
    f32 var_f1 = 0.0f;
    f32 temp_f2 = arg0->unk14 + fparg0;

    arg0->unk14 = temp_f2;
    if (temp_f2 < 0.0f || (var_f1 = arg0->unk10 - arg0->unkC, var_f1 < temp_f2)) {
        arg0->unk14 = var_f1;
    }
}
