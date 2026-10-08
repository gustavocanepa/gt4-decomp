typedef int s32;

struct Elem {
    char pad[0x148];
    s32 unk148;
};

extern "C" void func_003743D0(char *arg0, s32 arg1, s32 arg2) {
    ((Elem *)(arg0 + arg1 * 0x19C))->unk148 = arg2;
}
