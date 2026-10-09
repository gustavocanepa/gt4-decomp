typedef int s32;
typedef float f32;

struct Elem005F5AF0 {
    char pad0[0x60];
    f32 unk60;
};

extern "C" void func_005F5AF0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5AF0 *)arg0)->unk60 = fparg0;
}
