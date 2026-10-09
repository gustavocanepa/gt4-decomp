typedef int s32;
typedef float f32;

struct Elem005F5910 {
    char pad0[0x3C];
    f32 unk3C;
};

extern "C" void func_005F5910(char *arg0, s32 arg1, f32 fparg0) {
    arg0 = arg0 + arg1 * 0x6C;
    ((struct Elem005F5910 *)arg0)->unk3C = fparg0;
}
