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
    bool isObject() const { return type == 10; }
};
struct Stack { s32 f0; s32 f4; Val *top; };
struct Obj { char pad[0x58]; void *f58; };

extern "C" f32 func_00477460(const Val *);
extern "C" void func_00480FA0(Stack *, s32);
extern "C" void func_00480B58(void *, Obj *, s32);
extern "C" void func_0057D9C0(const char *, ...);
extern char D_006AD940[];

extern "C" Val func_0047B490(Obj *self, s32 argc, Stack *st) {
    if (argc) {
        Val a(st->top[-1]);
        func_00480FA0(st, argc);
        if (a.isObject()) {
            if (self->f58)
                func_00480B58(self->f58, self, a.v);
        } else {
            func_00477460(&a);
            func_0057D9C0(D_006AD940);
        }
    }
    return Val();
}
