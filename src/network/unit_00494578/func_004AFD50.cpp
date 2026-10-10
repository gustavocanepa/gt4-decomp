struct Obj {
    char pad[0x30];
    void *m30;
    int m34;
    int m38;
};
extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" void func_004AC470(void *p);
extern "C" char D_0084D5A0[];

extern "C" void func_004AFD50(Obj *o)
{
    void *p = 0;
    func_00576100(D_0084D5A0);
    if (o->m38) {
        p = o->m30;
        o->m38 = 0;
        o->m30 = 0;
    }
    func_00576140(D_0084D5A0);
    if (p)
        func_004AC470(p);
}
