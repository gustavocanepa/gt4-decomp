typedef int s32;
typedef float f32;

struct Elem005F5990 {
    char pad0[0x4C];
    f32 unk4C;
};

extern "C" void func_005F5990(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5990 *)arg0)->unk4C = fparg0;
}
