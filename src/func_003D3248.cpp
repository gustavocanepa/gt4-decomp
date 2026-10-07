typedef int s32;

struct Elem {
    char pad[0xB38];
    s32 unkB38;
};

extern "C" void func_003D3248(char *arg0, s32 arg1) {
    ((Elem *)(arg0 + arg1 * 0x8D0))->unkB38 = 1;
}
