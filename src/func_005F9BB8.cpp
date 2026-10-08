typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x1C];
    f32 unk1C;
};

extern "C" s32 func_005F9BB8(Obj *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk1C > 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
