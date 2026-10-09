typedef int s32;
typedef float f32;

struct Elem005F5880 {
    char pad0[0x8];
    f32 unk8;
};

extern "C" void func_005F5880(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5880 *)arg0)->unk8 = fparg0;
}
