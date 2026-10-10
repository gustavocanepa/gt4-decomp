typedef int s32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
};
struct Ctx { char pad[0x164]; s32 f164; };

extern "C" void func_00476A08(Val *);
extern "C" Val func_00484988(s32 v, s32 x, s32 y, Val *self, s32 z, s32 w, Ctx *ctx);
extern "C" Val func_0047B8B0(s32 *v, s32 x, s32 z, s32 w, Ctx *ctx);
extern "C" Val func_0047CB08(s32 *v, s32 x, s32 c, s32 z);
extern "C" Val func_0047C3C8(s32 x, s32 c, s32 z);
extern "C" Val func_0047C778(s32 *v, s32 x, s32 c, s32 z);
extern "C" Val func_0047CE40(Val *self, s32 x, s32 c, s32 z);

extern "C" Val func_00477C40(Val *self, s32 x, s32 y, s32 z, s32 w, Ctx *ctx) {
    switch (self->type) {
    case 7:
        return func_00484988(self->v, x, y, self, z, w, ctx);
    case 10:
        return func_0047B8B0(&self->v, x, z, w, ctx);
    case 11:
        return func_0047CB08(&self->v, x, ctx->f164, z);
    case 8:
        return func_0047C3C8(x, ctx->f164, z);
    case 9:
        return func_0047C778(&self->v, x, ctx->f164, z);
    case 3:
    case 4:
        return func_0047CE40(self, x, ctx->f164, z);
    default: {
        Val tmp;
        func_00476A08(&tmp);
        return tmp;
    }
    }
}
