typedef int s32;
void func_0050A978(char *a);
extern void (*D_008A03C8)(char *a, s32 b);
extern s32 D_008A01A0;
s32 func_005125F0(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    if (*(s32 *)(arg3 + 0x18) == 0) func_0050A978(arg3 + 0x44);
    if (D_008A03C8 != 0) D_008A03C8(arg3, D_008A01A0);
    return 0xC4;
}
