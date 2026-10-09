typedef int s32;

struct Elem_003D3040 {
    char pad0[0x16C];
    s32 unk16C;
    s32 unk170;
    char pad1[0x178 - 0x170 - 4];
};

extern "C" void func_003D3040(char *arg0, s32 arg1) {
    Elem_003D3040 *p = (Elem_003D3040 *)(arg0 + arg1 * 0x8D0 + 0x3E4);
    s32 i = 6;

    do {
        i -= 1;
        p->unk170 = p->unk16C;
        p++;
    } while (i != 0);
}
