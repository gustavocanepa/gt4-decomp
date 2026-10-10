struct Widget {
    void *ctx;
    int pad4[3];
    int x, y, w, h;
};

extern "C" void func_004AA4A0(Widget *w);
extern "C" int func_00105830(Widget *w);
extern "C" void func_004A5178(void *ctx, int a, int color, int x0, int y0, int x1, int y1, int b);

extern "C" void func_001059F8(Widget *wd, int b, int a)
{
    func_004AA4A0(wd);
    func_004A5178(wd->ctx, a, func_00105830(wd), wd->x, wd->y, wd->x + wd->w, wd->y + wd->h, b);
}
