typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xD38];
    s32 unkD38;
    f32 unkD3C;
};

extern "C" void RaceBase__virtual_29(struct Obj *arg0, f32 fparg0) {
    s32 var_v0 = 1;
    if (fparg0 == 1.0f) {
        var_v0 = 0;
    }
    arg0->unkD38 = var_v0;
    arg0->unkD3C = fparg0;
}
