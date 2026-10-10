typedef int s32;
void *exception__structor_0(s32);
void func_00474F38(void *a, s32 b, s32 c, s32 d);
void func_00475D78(void *a, char *b, void *c);
extern char D_003C3FE0[];
void func_003C46C8(char *arg0) {
    char *temp_v0;
    if (*(s32 *)(arg0 + 0xC) != 0 && *(s32 *)(arg0 + 0x14) != 0 && *(s32 *)(arg0 + 0x10) == 0) {
        temp_v0 = exception__structor_0(0x19C);
        func_00474F38(temp_v0, *(s32 *)(arg0 + 0xC), 0, *(s32 *)(arg0 + 0x14));
        *(char **)(arg0 + 0x10) = temp_v0;
        func_00475D78(temp_v0, D_003C3FE0, arg0);
        *(s32 *)(*(char **)(arg0 + 0x10) + 0x10) = 0;
    }
}
