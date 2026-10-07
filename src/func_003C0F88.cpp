typedef float f32;

struct S003C0F88 {
    char pad0[0xD4];
    f32 unkD4;
};

extern "C" f32 D_006A29D4;

extern "C" f32 func_003C0F88(S003C0F88 *arg0) {
    f32 temp_f1 = arg0->unkD4;

    if (temp_f1 < 0.0f) {
        return D_006A29D4;
    }
    return temp_f1;
}
