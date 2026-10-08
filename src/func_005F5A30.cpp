typedef int s32;
typedef float f32;

struct Elem005F5A30 {
    char pad0[0x48];
    f32 unk48;
};

extern "C" void func_005F5A30(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5A30 *)arg0)->unk48 = fparg0;
}
