typedef int s32;
typedef float f32;

struct Elem005F58D0 {
    char pad0[0x34];
    f32 unk34;
};

extern "C" void func_005F58D0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F58D0 *)arg0)->unk34 = fparg0;
}
