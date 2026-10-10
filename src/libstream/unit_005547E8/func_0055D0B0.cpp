/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Context {
    void *result;
    void *key;
    int depth;
};

struct Index {
    void *root;
    int pad4;
    unsigned long hash;
};

extern "C" void *func_0055C758(void *root, unsigned long hash);
extern "C" void func_0055C9A0(void *root, Index *self, int (*visit)(void *, Context *), Context *ctx,
                              int (*leave)(void *, Context *));
extern "C" int func_0055D070(void *node, Context *ctx);
extern "C" int func_0055D028(void *node, Context *ctx);

extern "C" void *func_0055D0B0(Index *self, void *key)
{
    void *r = func_0055C758(self->root, self->hash);
    if (r != 0)
        return r;
    Context ctx;
    ctx.key = key;
    ctx.result = 0;
    ctx.depth = 0;
    func_0055C9A0(self->root, self, func_0055D070, &ctx, func_0055D028);
    return ctx.result;
}
