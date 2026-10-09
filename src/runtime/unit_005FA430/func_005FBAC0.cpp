typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xD4];
    f32 unkD4;
};

extern "C" s32 func_005FBAC0(Obj *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unkD4 >= 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
