struct Obj { char pad[0x74]; void *target; };
extern "C" void func_00397AE8(void *, int, int);

extern "C" void func_00397288(Obj *o, int x, const unsigned short *list)
{
    void *t = o->target;
    if (list) {
        int n = *list++;
        for (int i = 0; i < n; i++) func_00397AE8(t, x, list[i]);
    } else {
        func_00397AE8(t, x, -1);
    }
}
