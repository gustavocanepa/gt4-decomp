typedef int s32;
void func_005A4724(char *a, char *b, s32 c);
void func_005460C8(char *a, s32 b);
void func_00544B38(char *arg0, char *arg1, s32 arg2) {
    char sp[0x80];
    func_005A4724(sp, arg1, 0x80);
    func_005460C8(sp, arg2);
    func_005A4724(arg0, sp, 0x80);
}
