typedef int s32;
s32 func_002208E8(char *a, s32 b, s32 c, s32 d);
void func_0054DF90(s32 a, char *b, s32 c);
void func_001FD4A8(char *arg0, s32 arg1) {
    char sp[0x80];
    func_002208E8(sp, 0x80, arg1, 0);
    func_0054DF90(*(s32 *)(arg0 + 0xB4), sp, 0x500000);
    *(s32 *)(arg0 + 0xDC) = 1;
}
