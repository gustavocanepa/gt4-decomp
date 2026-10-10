typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);
extern "C" const char *func_004772A8(Val *);
extern "C" s32 func_0057F238(const char *, const char *);

extern "C" s32 func_004780F8(const Val *a, const Val *b) {
    Val ta, tb;
    s32 r;
    func_00476768(&ta, a);
    func_00476768(&tb, b);
    r = func_0057F238(func_004772A8(&ta), func_004772A8(&tb)) > 0;
    func_004768C0(&tb);
    func_004768C0(&ta);
    return r;
}
