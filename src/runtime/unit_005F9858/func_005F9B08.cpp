typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x20];
    f32 unk20;
};

extern "C" s32 func_005F9B08(Obj *arg0) {
    s32 var_v0;

    f32 a = arg0->unk20;
    var_v0 = 1;
    if (!(0.0f < a)) {
        var_v0 = 0;
    }
    return var_v0;
}
