struct Callbacks {
    char pad[0x18];
    int (*draw)(void *ctx, int buffer);
    void *ctx;
};

extern "C" Callbacks D_0064C480;
extern "C" int D_00654D74;
extern "C" int D_00654D78;
extern "C" int D_00654DA0;

extern "C" void func_00563680(int enable)
{
    if (enable) {
        if (D_00654DA0 == 3)
            D_0064C480.draw(D_0064C480.ctx, D_00654D78);
        else
            D_0064C480.draw(D_0064C480.ctx, D_00654D74);
    }
}
