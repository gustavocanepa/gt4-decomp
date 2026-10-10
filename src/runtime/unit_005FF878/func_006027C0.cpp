struct Obj {
    virtual int v00(int);
    virtual int v01(int);
    virtual int v02(int);
    virtual int v03(int);
};
extern "C" int func_006027C0(Obj *arg0, int a1) {
    return arg0->v03(a1);
}
