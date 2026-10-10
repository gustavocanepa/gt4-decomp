typedef int s32;
int func_005A6AB0(char *a, char *b, s32 c);
void func_0039F110(char *arg0, char *arg1, s32 arg2, char *arg3) {
    arg3 += 0x350C;
    if (arg3 != 0) {
        arg2 -= 1;
        func_005A6AB0(arg1, arg3, arg2);
        arg1[arg2] = 0;
    }
}
