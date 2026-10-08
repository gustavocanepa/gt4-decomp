typedef int s32;
typedef float f32;

struct Elem {
    char pad[0xC];
    f32 unkC;
};

extern "C" void func_005F58A0(char *arg0, s32 arg1, f32 arg2) {
    arg0 = arg0 + arg1 * 0x6C;
    ((Elem *)arg0)->unkC = arg2;
}
