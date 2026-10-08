typedef int s32;
typedef float f32;

struct Elem005F5A50 {
    char pad0[0x64];
    f32 unk64;
};

extern "C" void func_005F5A50(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5A50 *)arg0)->unk64 = fparg0;
}
