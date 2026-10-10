typedef int s32;
void func_005A48D8(char *a, s32 b, s32 c);
void func_00505C00(char *a);
void func_004FFC60(void) {
    char sp[0x20];
    func_005A48D8(sp, 0, 0x16);
    sp[0x15] = 0;
    func_00505C00(sp);
}
