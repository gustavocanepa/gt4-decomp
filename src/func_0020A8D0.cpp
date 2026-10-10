typedef int s32;

struct Val_0020A8D0;
extern "C" void func_00208EE8(Val_0020A8D0 *self, const s32 *x);
extern "C" void func_00208F00(Val_0020A8D0 *self, const Val_0020A8D0 *other);

struct Val_0020A8D0 {
    s32 w;
    Val_0020A8D0(const s32 &x) { func_00208EE8(this, &x); }
    Val_0020A8D0(const Val_0020A8D0 &o) { func_00208F00(this, &o); }
};

struct Vec_0020A8D0 {
    s32 alloc;
    Val_0020A8D0 *start;
    Val_0020A8D0 *finish;
    s32 size() const { return finish - start; }
    Val_0020A8D0 &operator[](s32 i) { return start[i]; }
};

struct Obj_0020A8D0 {
    char pad0[0x10];
    Vec_0020A8D0 values;
};

Val_0020A8D0 func_0020A8D0(Obj_0020A8D0 *o, s32 i) {
    Vec_0020A8D0 &v = o->values;
    s32 n = v.size();
    if (i < 0 || i >= n) {
        return Val_0020A8D0(0);
    }
    return v[i];
}
