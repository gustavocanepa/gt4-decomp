struct In {
    char pad[0x20];
    virtual int v00(int);
    virtual int v01(int);
    virtual int v02(int);
    virtual int v03(int);
};
struct Out { char pad[0x60]; In *p; };
extern "C" int func_005FB8C0(Out *arg0, int arg1) {
    return arg0->p->v03(arg1);
}
