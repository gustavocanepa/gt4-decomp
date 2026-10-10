struct Inner {
    char pad[0x18];
    void *target;
};

struct Ctrl {
    Inner *inner;
    char pad[0x2C];
    int value;
};

extern "C" void *func_00451020(Ctrl *c);
extern "C" void func_00455300(void *target, int value, void *ctx);

extern "C" void func_00453340(Ctrl *c, int value)
{
    if (c->inner) {
        void *target = c->inner->target;
        void *ctx = func_00451020(c);
        if (target && ctx) {
            c->value = value;
            func_00455300(target, value, ctx);
        }
    }
}
