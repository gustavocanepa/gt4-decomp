struct Inner {
    char pad[0x18];
    int speed;
};

struct Obj {
    Inner *inner;
};

extern "C" void func_0034D0F8(Obj *o, int which, int *enabled, int *value, int arg4);

extern "C" void func_00347108(Obj *o, int which, int *enabled, int *value, int arg4)
{
    int s = o->inner->speed;
    if (s != 0) {
        int a, b;
        if (s > 0) {
            a = -s;
            b = -10;
            if (a > -20)
                a = -20;
        } else {
            a = -10;
            b = s;
            if (b > -20)
                b = -20;
        }
        *enabled = 1;
        *value = !which ? b : a;
    }
    return func_0034D0F8(o, which, enabled, value, arg4);
}
