typedef int s32;

struct Elem003D32B0 {
    char pad[0x840];
    s32 unk840;
    char pad2[0x9B8 - 0x840 - 4];
    s32 unk9B8;
};

extern "C" void func_003D32B0(char *arg0, s32 arg1) {
    s32 v1 = *(s32 *)(arg0 + arg1 * 4 + 0x969C);

    if (v1 != 0) {
        struct Elem003D32B0 *p = (struct Elem003D32B0 *)(arg0 + arg1 * 0x8D0);
        p->unk840 = 1;
        p->unk9B8 = 1;
    }
}
