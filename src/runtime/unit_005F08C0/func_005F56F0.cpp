typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x14];
    f32 unk14;
};

extern "C" f32 func_005F56F0(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0x6C;
    return ((Elem *)arg0)->unk14;
}
