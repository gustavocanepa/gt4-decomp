typedef int s32;
typedef float f32;
typedef signed char s8;

struct Obj003D7648 {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_003F2E10(s32 arg0, s8 arg1, f32 arg2);

extern "C" s32 func_003D7670(Obj003D7648 *arg0, s32 arg1) {
    char *p = (char *)arg0 + arg1;
    return func_003F2E10(arg0->unk4, *(s8 *)(p + 0xC), 0.0f);
}
