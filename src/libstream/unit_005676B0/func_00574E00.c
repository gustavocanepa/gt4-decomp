typedef int s32;
void func_005768D8(char *a);
void func_00574E00(char *arg0) {
    if (*(s32 *)(arg0 + 0x28) != 0) {
        func_005768D8(arg0);
        return;
    }
    *(s32 *)(arg0 + 0x2C) = 1;
}
