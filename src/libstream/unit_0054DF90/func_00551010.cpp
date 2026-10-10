struct Ctx { int handle; char pad[0x3C]; char path[0x40]; };
extern "C" Ctx D_0086F800;
extern "C" void func_00578500(int handle);
extern "C" char *func_005A609C(char *dst, const char *src); /* strcpy */
extern "C" void func_00578168(Ctx *ctx, int cmd, int a, void *buf, int size);

extern "C" void func_00551010(const char *path)
{
    Ctx *ctx = &D_0086F800;
    func_00578500(ctx->handle);
    func_005A609C(ctx->path, path);
    func_00578168(ctx, 8, 0, 0, 0);
}
