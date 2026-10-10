/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

/* the script value: type 1 is nil; func_004768C0 releases the payload and sets nil */
struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
};
extern "C" const char *func_004772A8(Val *);
extern "C" u32 func_0057F260(const char *s);
struct String2;
extern "C" String2 *func_005D2C20(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);
struct String2 {
    char *dat;
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005D2C20(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String2 &operator=(const char *s) { return assign(s); }
};

struct Obj { char pad[0x60]; String2 str; };

extern "C" void func_00479620(Obj *o, const Val &v) {
    Val t(v);
    o->str = func_004772A8(&t);
}
