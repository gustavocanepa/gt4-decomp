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
extern "C" void func_00477208(Val *, void *);

struct Obj { char pad[0x58]; Obj *f58; };

extern "C" Val func_0047AF80(Obj *o) {
    Val t;
    func_00477208(&t, o->f58 ? o->f58 : o);
    return t;
}
