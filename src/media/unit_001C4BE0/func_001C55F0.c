typedef int s32;
s32 func_00574D78(void);
void func_005D0A28(char *a);
void func_001C55F0(char *arg0) {
    func_00574D78();
    *(s32 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x38) = 0;
    *(s32 *)(arg0 + 0x3C) = 0;
    *(s32 *)(arg0 + 0x40) = -1;
    *(s32 *)(arg0 + 0x44) = -1;
    func_005D0A28(arg0 + 0x48);
}
