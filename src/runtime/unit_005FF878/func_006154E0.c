typedef int s32;
void func_006154E0(char *arg0, s32 arg1) {
    if (*(s32 *)arg0 & 0x100) {
        *(s32 *)(arg0 + 0x24) += arg1;
    } else {
        *(s32 *)(arg0 + 4) += arg1;
    }
}
