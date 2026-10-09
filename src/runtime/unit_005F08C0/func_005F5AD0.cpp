typedef int s32;
typedef float f32;

struct Elem005F5AD0 {
    char pad0[0x5C];
    f32 unk5C;
};

extern "C" void func_005F5AD0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5AD0 *)arg0)->unk5C = fparg0;
}
