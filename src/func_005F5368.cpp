typedef int s32;

struct Elem {
    char pad[0x194];
    s32 unk194;
};

extern "C" void func_005F5368(char *arg0, s32 arg1, s32 arg2) {
    ((Elem *)(arg0 + arg1 * 0x19C))->unk194 = arg2;
}
