typedef int s32;
typedef float f32;

struct Obj002E57A0 {
    char pad0[0x3AC];
    s32 unk3AC;
    s32 unk3B0;
};

extern "C" f32 func_002E57A0(struct Obj002E57A0 *arg0) {
    f32 var_f0;

    var_f0 = (f32)arg0->unk3B0 / (f32)arg0->unk3AC;
    if (var_f0 > 1.0f) {
        var_f0 = 1.0f;
    }
    return var_f0;
}
