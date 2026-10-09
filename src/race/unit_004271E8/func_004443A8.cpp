typedef int s32;
extern char D_006235A8[];
extern "C" long long func_00443E00(void *, const char *, s32);
extern "C" s32 func_00444440(void *, long long);
extern "C" s32 func_004443A8(void *record, const char *label) {
    long long code = func_00443E00(D_006235A8, label, 0);
    if (code == -1) {
        code = func_00443E00(D_006235A8, label, 0x26);
        if (code == -1) return 0;
    }
    return func_00444440(record, code);
}
