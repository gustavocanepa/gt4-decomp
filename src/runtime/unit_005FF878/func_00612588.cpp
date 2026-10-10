typedef void (*Handler)(int a, int b, int c);

struct Dispatcher {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual Handler handler();
};

extern "C" void func_00612588(Dispatcher *d, int a, int b, int c)
{
    d->handler()(a, b, c);
}
