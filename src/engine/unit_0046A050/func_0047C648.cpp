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
extern "C" void func_00476B30(Val *, s32);
extern "C" void func_00480FA0(void *, s32);

extern "C" Val func_0047C648(void *self, s32 n, void *list) {
    func_00480FA0(list, n);
    Val t;
    func_00476B30(&t, 0);
    return t;
}
