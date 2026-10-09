typedef int s32;

struct Elem {
    char pad[0x848];
    s32 unk848;
    char pad2[0x9C0 - 0x848 - 4];
    s32 unk9C0;
};

extern "C" void func_003D3228(char *arg0, s32 arg1) {
    Elem *temp_a0 = (Elem *)(arg0 + arg1 * 0x8D0);
    temp_a0->unk848 = 1;
    temp_a0->unk9C0 = 1;
}
