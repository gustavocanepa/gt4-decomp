typedef int s32;
extern char D_006550F8[];
s32 func_00565E50(char *a, s32 b, void *c);
s32 func_005565E0(char *arg0) {
    char sp[0x30];
    return func_00565E50(D_006550F8, *(s32 *)(arg0 + 0x5C), sp) == 0;
}
