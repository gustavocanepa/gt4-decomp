typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x1C];
    f32 unk1C;
};

extern "C" f32 func_005F5620(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + arg1 * 0x6C))->unk1C;
}
