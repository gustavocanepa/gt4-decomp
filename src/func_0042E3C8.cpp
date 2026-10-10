struct Rect { char pad[0x1C]; float x, y, w, h; };
extern "C" void func_004AA168(unsigned int color);
extern "C" void func_004A2808(int mode, float v);
extern "C" void func_004A4550(int a, int b);
extern "C" void func_0042DE50(void *ctx, float x, float y, float w, float h);

extern "C" void func_0042E3C8(Rect *r, void *ctx)
{
    func_004AA168(0x80FFFFFF);
    func_004A2808(0x48, 0.0f);
    func_004A4550(2, 1);
    func_004A4550(3, 1);
    func_0042DE50(ctx, r->x, r->y, r->w, r->h);
}
