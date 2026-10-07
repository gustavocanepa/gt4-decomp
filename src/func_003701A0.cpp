typedef float f32;
typedef int s32;

struct Obj {
    char pad[0xE0];
    f32 unkE0;
};

extern "C" s32 func_00370010(f32 arg0);

extern "C" s32 func_003701A0(Obj *arg0) {
    return func_00370010(arg0->unkE0);
}
