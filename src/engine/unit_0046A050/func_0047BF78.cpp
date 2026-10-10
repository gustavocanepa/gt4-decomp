/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val {
    int data[2];
};

struct Ctx {
    int pad0[2];
    Val *sp;
};

extern "C" float func_00477460(Val *v);
extern "C" void func_00480F78(Ctx *ctx);
extern "C" void func_00480FA0(Ctx *ctx, unsigned int n);
extern "C" float func_0057D6C0(float a, float b);

extern "C" float func_0047BF78(unsigned int argc, Ctx *ctx) {
    float r;
    if (argc >= 2) {
        float a = func_00477460(ctx->sp - 1);
        func_00480F78(ctx);
        float b = func_00477460(ctx->sp - 1);
        func_00480FA0(ctx, argc - 1);
        r = func_0057D6C0(a, b);
    } else {
        func_00480FA0(ctx, argc);
        r = 0.0f;
    }
    return r;
}
