typedef int s32;
typedef float f32;

struct Elem005F59D0 {
    char pad0[0x54];
    f32 unk54;
};

extern "C" void func_005F59D0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F59D0 *)arg0)->unk54 = fparg0;
}
