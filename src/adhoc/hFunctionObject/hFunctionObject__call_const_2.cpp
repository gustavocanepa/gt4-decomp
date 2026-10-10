struct In {
    char pad[0x4];
    virtual void v000(int, int, int);
    virtual void v001(int, int, int);
    virtual void v002(int, int, int);
    virtual void v003(int, int, int);
    virtual void v004(int, int, int);
    virtual void v005(int, int, int);
    virtual void v006(int, int, int);
    virtual void v007(int, int, int);
    virtual void v008(int, int, int);
    virtual void v009(int, int, int);
    virtual void v010(int, int, int);
    virtual void v011(int, int, int);
    virtual void v012(int, int, int);
    virtual void v013(int, int, int);
    virtual void v014(int, int, int);
    virtual void v015(int, int, int);
};
struct Out { char pad[0x10]; In *p; };
extern "C" void hFunctionObject__call_const_2(Out *arg0, int a1, int a2, int a3) {
    arg0->p->v015(a1, a2, a3);
}
