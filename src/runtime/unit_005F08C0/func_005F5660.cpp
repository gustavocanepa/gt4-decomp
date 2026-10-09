typedef int s32;
typedef float f32;

struct Elem005F5660 {
    char pad0[0x24];
    f32 unk24;
};

extern "C" f32 func_005F5660(char *arg0, s32 arg1) {
    return ((struct Elem005F5660 *)(arg0 + arg1 * 0x6C))->unk24;
}
