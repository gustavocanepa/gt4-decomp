struct func_00474B50_Save {
    int a;
    int b;
};

struct func_00474B50_Key {
    char pad0[0x20];
    float weight;
};

struct func_00474B50_Keys {
    func_00474B50_Key *keys;
    int count;
    func_00474B50_Key *at(int i) { return &keys[i]; }
};

struct func_00474B50_Anim {
    short type;
    short start;
    short pad4;
    short index;
    char pad8[0x18 - 0x8];
    func_00474B50_Keys keys;
};

struct func_00474B50_Tables {
    char pad0[0x30];
    char *t30;
    int pad34;
    char *t38;
    int pad3C;
    char *t40;
    char pad44[0x58 - 0x44];
    char *t58;
    int pad5C;
    char *t60;
    char pad64[0xA0 - 0x64];
    char *tA0;
};

struct func_00474B50_Ctx {
    char pad0[0x6E18];
    func_00474B50_Save save;
    func_00474B50_Tables *tables;
};

extern "C" {
void func_004A53F8(void);
void func_004A5400(void);
void func_00474E08(func_00474B50_Key *out, func_00474B50_Key *a, func_00474B50_Key *b, float t);
void func_00474E88(func_00474B50_Key *key, func_00474B50_Ctx *ctx);
void func_0047EA08(void *p, func_00474B50_Ctx *ctx);
void func_0047F258(void *p, func_00474B50_Ctx *ctx, float w);
void func_00474568(void *p, func_00474B50_Ctx *ctx, float t);
void func_00479958(void *p, func_00474B50_Ctx *ctx);
void func_00479C70(void *p, func_00474B50_Ctx *ctx);
void func_00479180(void *p, func_00474B50_Ctx *ctx, float t);
}

extern "C" void func_00474B50(func_00474B50_Anim *anim, func_00474B50_Ctx *ctx, int frame, float time) {
    float frac = time - (float)(int)time;
    int k = frame - anim->start;
    func_00474B50_Keys *ks = &anim->keys;
    func_004A53F8();
    func_00474B50_Save save = ctx->save;
    float w;
    if (k < ks->count - 1) {
        func_00474B50_Key tmp;
        func_00474E08(&tmp, ks->at(k), ks->at(k + 1), frac);
        func_00474E88(&tmp, ctx);
        w = tmp.weight;
    } else if (ks->count != 0) {
        func_00474E88(&ks->keys[ks->count - 1], ctx);
        w = ks->keys[ks->count - 1].weight;
    } else {
        w = 0.0f;
    }
    switch (anim->type) {
    case 0:
        func_0047EA08(ctx->tables->t38 + anim->index * 24, ctx);
        break;
    case 1:
        func_0047F258(ctx->tables->t40 + anim->index * 40, ctx, w);
        break;
    case 2:
        func_00474568(ctx->tables->t30 + anim->index * 36, ctx, time - (float)anim->start);
        break;
    case 4:
        func_00479958(ctx->tables->t58 + anim->index * 48, ctx);
        break;
    case 5:
        func_00479C70(ctx->tables->t60 + anim->index * 52, ctx);
        break;
    case 6:
        func_00479180(ctx->tables->tA0 + anim->index * 20, ctx, time - (float)anim->start);
        break;
    }
    ctx->save = save;
    func_004A5400();
}
