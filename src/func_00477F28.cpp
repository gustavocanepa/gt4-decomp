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

extern "C" s32 func_00477F28(const Val *a, const Val *b) {
    if (a->isString() || b->isString()) {
        Val ta, tb;
        s32 r;
        func_00476768(&ta, a);
        func_00476768(&tb, b);
        r = func_0057F238(func_004772A8(&ta), func_004772A8(&tb)) < 0;
        func_004768C0(&tb);
        func_004768C0(&ta);
        return r;
    }
    return func_00477460(a) < func_00477460(b);
}
