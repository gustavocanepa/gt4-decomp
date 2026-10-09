typedef int s32;
extern char D_006235A8[];
extern "C" const char *func_00443E60(void *, long long);
extern "C" char *func_005A609C(char *, const char *);
extern "C" s32 func_00447CA0(long long code, char *dest) {
    const char *label = func_00443E60(D_006235A8, code);
    if (label) { func_005A609C(dest, label); return 1; }
    *dest = 0;
    return 0;
}
