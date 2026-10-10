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
struct Entry { s32 a, b; };
struct Def { char pad[0xA8]; Entry *entries; };
struct Obj {
    Def *def;
    char pad4[0x5C];
    s32 f60;
    s32 f64;
    s32 f68;
    char pad6C[0x20];
    s32 f8C;
};

extern "C" s32 func_004749B8(s32, s32);
extern "C" Val func_004817E8(s32 *, Entry *, s32);
extern "C" void func_0047FCE0(Obj *);

extern "C" void func_0047FEC0(Obj *o, s32 arg) {
    for (;;) {
        s32 i = func_004749B8(o->f60, o->f64);
        if (i < 0)
            return;
        func_004817E8(&o->f8C, o->def->entries + i, arg);
        if (o->f68 < 0)
            return;
        func_0047FCE0(o);
    }
}
