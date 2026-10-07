typedef int s32;
typedef float f32;

struct Struct_00354E38 {
    char pad0[0x5D0];
    f32 unk5D0;
};

extern "C" s32 func_00354E38(Struct_00354E38 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk5D0 > 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
