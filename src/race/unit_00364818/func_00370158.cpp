typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x60];
    f32 unk60;
};

extern "C" s32 func_0036FFC0(f32 arg0);

extern "C" s32 func_00370158(Obj *arg0) {
    return func_0036FFC0(arg0->unk60);
}
