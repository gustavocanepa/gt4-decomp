typedef int s32;
typedef float f32;

struct Elem005F5A70 {
    char pad0[0x68];
    f32 unk68;
};

extern "C" void func_005F5A70(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5A70 *)arg0)->unk68 = fparg0;
}
