typedef int s32;
typedef float f32;

struct Struct_003446B8 {
    char pad0[0x590];
    f32 unk590;
};

extern "C" s32 func_003446B8(Struct_003446B8 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk590 > 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
