typedef int s32;
typedef float f32;

struct Obj;

extern "C" s32 func_0038D0C0(Obj *arg0);

extern "C" f32 func_0038D9E8(Obj *arg0) {
    return *(f32 *)(func_0038D0C0(arg0) + 0x78);
}
