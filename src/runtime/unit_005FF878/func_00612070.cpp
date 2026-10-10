struct Ctx { int handle; char pad[0x3F4]; int state; };

extern "C" char D_00873DC0[];
extern "C" void func_00578500(int handle);
extern "C" void func_00578168(Ctx *ctx, int a, int b, void *buf, int size);

extern "C" void func_00612070(struct Ctx *ctx)
{
    func_00578500(ctx->handle);
    ctx->state = 1;
    func_00578168(ctx, 3, 0, D_00873DC0, 0x80);
}
