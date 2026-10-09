typedef int s32;
typedef float f32;

struct Elem005F5A90 {
    char pad0[0x6C];
    f32 unk6C;
};

extern "C" void func_005F5A90(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5A90 *)arg0)->unk6C = fparg0;
}
