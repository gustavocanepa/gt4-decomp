extern void *PDISTD__global_font_manager;
extern "C" void func_00490290(void *, void *);
extern "C" int func_0048F790(void *, char *, int, const char *, float);
extern "C" char *func_005A609C(char *, const char *);

extern "C" void func_003DA668(char *dst, const char *src, void *ctx, float scale)
{
    if (ctx) func_00490290(PDISTD__global_font_manager, ctx);
    if (!func_0048F790(PDISTD__global_font_manager, dst, 0x80, src, scale)) func_005A609C(dst, src);
}
