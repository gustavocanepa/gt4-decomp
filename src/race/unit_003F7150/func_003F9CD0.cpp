typedef int s32;
typedef float f32;

struct Struct_003F9CD0 {
    char pad0[0x20];
    f32 unk20;
};

extern "C" s32 func_003F9CD0(Struct_003F9CD0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (arg0->unk20 == 0.0f) {
        var_v0 = 0;
    }
    return var_v0;
}
