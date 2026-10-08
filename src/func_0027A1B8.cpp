typedef float f32;
typedef int s32;

struct Obj {
    char pad0[0x18];
    f32 unk18;
};

extern "C" s32 func_0027A1B8(struct Obj *arg0, f32 fparg0) {
    f32 temp_f1 = arg0->unk18;

    if (temp_f1 > 0.0f) {
        arg0->unk18 = (f32)(temp_f1 - fparg0);
        return 1;
    }
    return 0;
}
