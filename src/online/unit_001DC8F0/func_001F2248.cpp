typedef int s32;

struct Str {
    char *p;
};

extern char D_006959D8[];
extern char D_00645570[];

extern "C" void func_001F1368(s32 arg0);
extern "C" void mUpdateContext__Sync(s32 arg0);
extern "C" s32 func_004F3128(void *arg0, const char *arg1, const char *arg2);

static inline const char *c_str(Str *s) {
    s32 len = *(s32 *)(s->p - 0x10);
    if (len == 0) {
        return D_006959D8;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_001F2248(s32 arg0, Str *a, Str *b) {
    while (func_004F3128(D_00645570, c_str(a), c_str(b)) == 0) {
        mUpdateContext__Sync(1);
    }
    func_001F1368(arg0);
}
