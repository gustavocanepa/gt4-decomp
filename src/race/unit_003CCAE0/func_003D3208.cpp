typedef int s32;

struct Elem003D3208 {
    char pad[0x558];
    s32 unk558;
    char pad2[0x6D0 - 0x558 - 4];
    s32 unk6D0;
};

extern "C" void func_003D3208(char *arg0, s32 arg1) {
    struct Elem003D3208 *temp_a0 = (struct Elem003D3208 *)(arg0 + arg1 * 0x8D0);
    temp_a0->unk558 = 1;
    temp_a0->unk6D0 = 1;
}
