typedef int s32;
typedef float f32;

struct Struct_00344658 {
    char pad0[0x594];
    f32 unk594;
};

extern "C" s32 func_00344658(struct Struct_00344658 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk594 > 0.25f)) {
        var_v0 = 0;
    }
    return var_v0;
}
