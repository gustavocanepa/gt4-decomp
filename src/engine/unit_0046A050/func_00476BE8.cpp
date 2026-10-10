typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" void *exception__structor_0(s32 size);
extern "C" void func_0047A278(void *self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" void func_00476BE8(Val *self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 type = 13;
    void *o;
    func_004768C0(self);
    self->type = type;
    o = exception__structor_0(0x20);
    func_0047A278(o, a, b, c, d, e, f);
    self->v = (s32)o;
}
