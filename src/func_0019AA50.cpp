typedef float f32;

struct Inner {
    char pad[0x40];
    f32 unk40;
};

struct Obj {
    char pad[0xA0];
    Inner *unkA0;
};

extern "C" f32 func_0019AA50(Obj *arg0) {
    f32 var_f0;
    Inner *temp_v0 = arg0->unkA0;

    var_f0 = 0.0f;
    if (temp_v0 != 0) {
        var_f0 = temp_v0->unk40;
    }
    return var_f0;
}
