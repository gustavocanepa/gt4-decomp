struct Base {
    virtual int v00(int);
    virtual int v01(int);
    virtual int v02(int);
    virtual int v03(int);
    virtual int v04(int);
    virtual int v05(int);
    virtual int v06(int);
    virtual int v07(int);
    virtual int v08(int);
    virtual int v09(int);
    virtual int v10(int);
    virtual int v11(int);
    virtual int v12(int);
    virtual int v13(int);
    virtual int v14(int);
    virtual int v15(int);
    virtual int v16(int);
    virtual int v17(int);
    virtual int v18(int);
    virtual int v19(int);
    virtual int v20(int);
    virtual int v21(int);
    virtual int v22(int);
    virtual int v23(int);
    virtual int v24(int);
};
struct Obj : Base {
    int m4;
};
extern "C" int func_005F79C8(Obj *o) {
    return o->v24(o->m4);
}
