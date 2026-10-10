typedef int s32;
extern char D_00686100[];
void func_003FF9A0(char *a);
void func_003FF910(char *arg0) {
    *(char **)(arg0 + 0x14) = D_00686100;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    func_003FF9A0(arg0);
}
