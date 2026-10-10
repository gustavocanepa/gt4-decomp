typedef int s32;
typedef unsigned int u32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476790(Val *, const Val *);
extern "C" u32 func_0057F260(const char *s);
struct String2;
extern "C" String2 *strobe__Any__setMember(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);
struct String2 {
    char *dat;
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *strobe__Any__setMember(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
};
struct Obj {
    char pad[0x16C];
    s32 f16C;
    s32 f170;
    Val val;
    String2 str;
};
extern "C" void func_00475DF8(Obj *self, s32 a, const char *s) {
    self->f16C = 1;
    self->f170 = a;
    func_004768C0(&self->val);
    self->str.assign(s);
}
