typedef int s32;
void func_0053DD68(char *arg0, s32 arg1, s32 arg2) {
    char *t;
    if (arg0 != 0) {
        if (arg1 == 0) {
            if (arg2 & 0x1000) {
                *(s32 *)(*(char **)(arg0 + 0x44) + 0xC) = 3;
                return;
            }
            if (arg2 & 0x800) {
                t = *(char **)(arg0 + 0x44);
                *(s32 *)(t + 0x203C) = 1;
                *(s32 *)(t + 0xC) = 3;
                return;
            }
        }
        *(s32 *)(*(char **)(arg0 + 0x44) + 0xC) = 8;
    }
}
