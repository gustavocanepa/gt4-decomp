typedef int s32;
typedef float f32;

struct Elem005F5AB0 {
    char pad0[0x58];
    f32 unk58;
};

extern "C" void func_005F5AB0(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5AB0 *)arg0)->unk58 = fparg0;
}
