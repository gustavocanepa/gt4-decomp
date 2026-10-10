typedef int s32;
void func_004B9A80(void *a, s32 b, s32 c);
void func_004BC428(void *a, s32 b);
void func_004B42E0(s32 arg0, s32 arg1) {
    char sp[0x100];
    func_004B9A80(sp, 0x100, arg0);
    func_004BC428(sp, arg1);
}
