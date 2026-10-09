typedef int s32;
typedef float f32;

struct Elem005F56D0 {
    char pad0[0x10];
    f32 unk10;
};

extern "C" f32 func_005F56D0(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0x6C;
    return ((struct Elem005F56D0 *)arg0)->unk10;
}
