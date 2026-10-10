typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val {
    s32 type;
    s32 v;
    bool isString() const { return (u32)(type - 3) < 2; }
};
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);
extern "C" const char *func_004772A8(Val *);
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" f32 func_00477460(const Val *);
extern "C" void func_00476B78(Val *, f32);
extern "C" u32 func_0057F260(const char *);
extern "C" s32 func_00476630(u32 len);
extern "C" char *func_005A609C(char *dst, const char *src);

extern "C" void func_00477DE0(Val *a, const Val *b) {
    if (a->isString() || b->isString()) {
        Val ta, tb;
        s32 type = 3;
        const char *sa, *sb;
        u32 la, lb;
        func_00476768(&ta, a);
        func_00476768(&tb, b);
        sa = func_004772A8(&ta);
        sb = func_004772A8(&tb);
        la = func_0057F260(sa);
        lb = func_0057F260(sb);
        func_004768C0(a);
        a->type = type;
        a->v = func_00476630(la + lb);
        func_005A609C((char *)a->v + 2, sa);
        func_005A609C((char *)a->v + la + 2, sb);
        func_004768C0(&tb);
        func_004768C0(&ta);
        return;
    }
    func_00476B78(a, func_00477460(a) + func_00477460(b));
}
