typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xD3C];
    f32 unkD3C;
    char pad2[0xD50 - 0xD3C - 4];
    s32 unkD50;
};

extern "C" f32 func_0038A2C8(Obj *arg0) {
    f32 var_f0 = 0.05f;
    if (arg0->unkD50 <= 0) {
        var_f0 = arg0->unkD3C;
    }
    return var_f0;
}
