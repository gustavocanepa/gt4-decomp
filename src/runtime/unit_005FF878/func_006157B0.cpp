struct Obj {
    char pad[0x50];
    virtual int v00(int, int);
    virtual int v01(int, int);
    virtual int v02(int, int);
    virtual int v03(int, int);
    virtual int v04(int, int);
    virtual int v05(int, int);
};
extern "C" int func_006157B0(Obj *arg0, int a1, int a2) {
    return arg0->v05(a1, a2);
}
