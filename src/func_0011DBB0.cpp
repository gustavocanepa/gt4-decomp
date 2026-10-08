typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0x40000];
    s32 arr[2];
    f32 scale;
};

extern "C" f32 func_0011DBB0(struct Obj *arg0, s32 arg1) {
    f32 scale = arg0->scale;
    s32 v = arg0->arr[arg1];

    return (f32)(v - 1) * scale;
}
