typedef int s32;
typedef float f32;

struct Inner {
    char pad[0x18];
    f32 unk18;
};

struct Obj {
    char pad[0x198];
    Inner *unk198;
};

extern "C" f32 func_0037C9C8(Obj *arg0) {
    f32 var_f0;
    Inner *temp_v0;

    temp_v0 = arg0->unk198;
    var_f0 = 0.0f;
    if (temp_v0 != 0) {
        var_f0 = temp_v0->unk18;
    }
    return var_f0;
}
