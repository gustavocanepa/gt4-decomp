typedef int s32;
s32 func_00557090(s32 a, s32 b);
void func_005570E0(s32 a, s32 b, char *c);
void func_00557728(s32 a, char *b);
void func_00556E48(s32 arg0, s32 arg1) {
    char sp[0x20];
    if (func_00557090(arg0, arg1) != 0) {
        func_005570E0(arg0, arg1, sp);
        func_00557728(arg0, sp);
    }
}
