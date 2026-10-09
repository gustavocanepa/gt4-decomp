typedef int s32;

struct Elem {
    char pad[0x13C];
    s32 unk13C;
};

extern "C" void func_005F53B0(char *arg0, s32 arg1, s32 arg2) {
    ((Elem *)(arg0 + arg1 * 0x19C))->unk13C = arg2;
}
