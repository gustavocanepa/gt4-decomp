struct Mat {
    float m[16];
};

struct Obj {
    char pad[0x18];
    char unk18[1];
};

struct Ctx {
    char pad[0x6E18];
    char unk6E18[1];
};

extern "C" void func_0047E400(Obj *, Mat *);
extern "C" void func_004A7698(Mat *);
extern "C" void func_0047E6E0(void *, void *);

extern "C" void func_00474E88(Obj *self, Ctx *ctx) {
    Mat m;
    func_0047E400(self, &m);
    func_004A7698(&m);
    func_0047E6E0(ctx->unk6E18, self->unk18);
}
