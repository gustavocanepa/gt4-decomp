typedef int s32;
typedef long long s64;
s32 func_00440B18(s32);
void func_00440B50(char *a, s32 b, s32 c);
void func_00440A68(char *arg0, s32 arg1, s32 arg2) {
    s32 i;
    char *p;
    s64 m;
    if (arg1 != 0) {
        func_00440B50(arg0, func_00440B18(arg1), arg2);
        return;
    }
    p = arg0 + 0x3F8;
    for (i = 0; i < 3; i++) {
        *(s64 *)p = -1;
        p -= 0x178;
    }
}
