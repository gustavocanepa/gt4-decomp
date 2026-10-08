typedef float f32;
typedef int s32;

struct Obj00384D88 {
    s32 unk0;
    union {
        f32 unk4;
        s32 arr0[32];
    };
    s32 arr1[32];
};

extern "C" void func_00384D88(struct Obj00384D88 *arg0, f32 fparg0) {
    s32 *p = arg0->arr0;
    s32 i;
    for (i = 0; i < 32; i++) {
        p[0] = 0;
        p[32] = 0;
        p++;
    }
    arg0->unk4 = fparg0;
    arg0->unk0 = 0;
}
