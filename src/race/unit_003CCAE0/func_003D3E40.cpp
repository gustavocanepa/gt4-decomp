typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x68];
    f32 unk68;
};

extern "C" s32 func_003D3E40(struct Obj *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0 = arg0->unk68 - (fparg1 * fparg0);

    arg0->unk68 = temp_f0;
    if (temp_f0 <= 0.0f) {
        arg0->unk68 = 0.0f;
        return 1;
    }
    return 0;
}
