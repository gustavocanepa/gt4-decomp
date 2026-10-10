typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);
extern "C" void func_004787B8(Val *, s32 type);

extern "C" s32 func_004789B8(const Val *self) {
    Val tmp;
    s32 r;
    func_00476768(&tmp, self);
    func_004787B8(&tmp, 10);
    r = tmp.v != 0x7F800000 && tmp.v != (s32)0xFF800000;
    func_004768C0(&tmp);
    return r;
}
