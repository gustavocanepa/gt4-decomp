typedef int s32;
typedef unsigned char u8;
s32 RaceEventQueue__check(char *a, s32 b, void *c, s32 d);
void func_003E1EA0(s32 a, char *b);
void func_003E1E10(s32 arg0, char *arg1) {
    char sp[0x10];
    s32 i;
    u8 n = *(u8 *)(arg1 + 0x906);
    for (i = 0; i < n; i++) {
        if (RaceEventQueue__check(arg1 + 0xF4, 0xA, sp, i) != 0) {
            func_003E1EA0(arg0, arg1);
        }
    }
}
