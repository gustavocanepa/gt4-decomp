typedef int s32;

struct Elem_003D3278 {
    char pad[0x550];
    s32 unk550;
    char pad2[0x6C8 - 0x550 - 4];
    s32 unk6C8;
};

extern "C" void func_003D3278(char *arg0, s32 arg1) {
    s32 v1 = *(s32 *)(arg0 + arg1 * 4 + 0x969C);

    if (v1 != 0) {
        struct Elem_003D3278 *temp_v0 = (struct Elem_003D3278 *)(arg0 + arg1 * 0x8D0);
        temp_v0->unk550 = 1;
        temp_v0->unk6C8 = 1;
    }
}
