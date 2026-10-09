typedef int s32;

struct Elem {
    char pad[0x144];
    s32 unk144;
};

extern "C" void func_003720A0(char *arg0, s32 arg1) {
    ((Elem *)(arg0 + arg1 * 0x19C))->unk144 = 6;
}
