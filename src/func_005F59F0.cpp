typedef int s32;
typedef float f32;

struct Elem005F59F0 {
    char pad0[0x40];
    f32 unk40;
};

extern "C" void func_005F59F0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F59F0 *)arg0)->unk40 = fparg0;
}
