typedef int s32;
typedef float f32;

struct Elem005F56A8 {
    char pad0[0xC];
    f32 unkC;
};

extern "C" f32 func_005F56A8(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0x6C;
    return ((struct Elem005F56A8 *)arg0)->unkC;
}
