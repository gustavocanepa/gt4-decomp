typedef int s32;
void memcpy(char *a, char *b, s32 c);
void func_00545EB8(char *a, s32 b);
void func_00544A88(char *arg0, char *arg1, s32 arg2) {
    char sp[0x80];
    memcpy(sp, arg1, 0x80);
    func_00545EB8(sp, arg2);
    memcpy(arg0, sp, 0x80);
}
