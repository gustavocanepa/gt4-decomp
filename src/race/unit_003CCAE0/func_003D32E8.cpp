typedef int s32;

extern "C" void func_003D32E8(char *arg0, s32 arg1) {
    s32 v1 = *(s32 *)(arg0 + arg1 * 4 + 0x969C);

    if (v1 != 0) {
        *(s32 *)(arg0 + arg1 * 0x8D0 + 0xB30) = 1;
    }
}
