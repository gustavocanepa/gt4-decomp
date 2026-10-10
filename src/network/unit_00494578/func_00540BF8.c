typedef struct func_00540BF8_Ctx func_00540BF8_Ctx;
struct func_00540BF8_Ctx {
    void *parser;
    unsigned int type;
    char pad8[0x210 - 0x8];
    void *data;
};

int func_00538BF8(void *pp, unsigned int size);
int func_00540FB8(func_00540BF8_Ctx *ctx, int a, int b);
void func_00540EB0(func_00540BF8_Ctx *ctx);
int func_00541150(void *parser, void *user);
void func_00541170(void *parser, void *handler);
void func_00541190(void *parser, void *handler);
void func_005411B0(void *parser, int a, void *handler);
void func_0053F400(void);
void func_0053F548(void);
void func_0053F5C0(void);
void func_0053FE40(void);
void func_0053FFD0(void);
void func_00540020(void);
void func_005404C8(void);
void func_00540738(void);
void func_00540788(void);
void func_00540818(void);
void func_00540AA0(void);
void func_00540B18(void);

int func_00540BF8(func_00540BF8_Ctx **out, unsigned int type, int arg) {
    func_00540BF8_Ctx *ctx = 0;
    int err;
    if (out == 0) return 2;
    goto start;
setup:
    ctx->type = type;
    func_00541150(ctx->parser, ctx);
    switch (type) {
    case 0:
        err = func_00538BF8(&ctx->data, 0x1304);
        if (err != 0) goto fail;
        func_00541170(ctx->parser, (void *)func_0053F400);
        func_00541190(ctx->parser, (void *)func_0053F548);
        func_005411B0(ctx->parser, 0, (void *)func_0053F5C0);
        break;
    case 8:
        err = func_00538BF8(&ctx->data, 0x4);
        if (err != 0) goto fail;
        func_00541170(ctx->parser, (void *)func_0053FE40);
        func_00541190(ctx->parser, (void *)func_0053FFD0);
        func_005411B0(ctx->parser, 0, (void *)func_00540020);
        break;
    case 7:
        err = func_00538BF8(&ctx->data, 0x4);
        if (err != 0) goto fail;
        func_00541170(ctx->parser, (void *)func_0053FE40);
        func_00541190(ctx->parser, (void *)func_0053FFD0);
        func_005411B0(ctx->parser, 0, (void *)func_00540020);
        break;
    case 10:
        err = func_00538BF8(&ctx->data, 0x100);
        if (err != 0) goto fail;
        func_00541170(ctx->parser, (void *)func_005404C8);
        func_00541190(ctx->parser, (void *)func_00540738);
        func_005411B0(ctx->parser, 0, (void *)func_00540788);
        break;
    case 11:
        err = func_00538BF8(&ctx->data, 0x1804);
        if (err != 0) goto fail;
        func_00541170(ctx->parser, (void *)func_00540818);
        func_00541190(ctx->parser, (void *)func_00540AA0);
        func_005411B0(ctx->parser, 0, (void *)func_00540B18);
        break;
    default:
        err = 4;
        break;
    }
    if (err != 0) goto fail;
    *out = ctx;
    return 0;
start:
    err = func_00538BF8(&ctx, 0x214);
    if (err != 0) goto fail;
    err = func_00540FB8(ctx, 0, arg);
    if (ctx->parser != 0 && err == 0) goto setup;
fail:
    func_00540EB0(ctx);
    return err;
}
