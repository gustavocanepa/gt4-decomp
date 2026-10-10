struct In {
    char pad[4];
    virtual void v000(void *, int);
    virtual void v001(void *, int);
    virtual void v002(void *, int);
    virtual void v003(void *, int);
    virtual void v004(void *, int);
    virtual void v005(void *, int);
    virtual void v006(void *, int);
    virtual void v007(void *, int);
    virtual void v008(void *, int);
    virtual void v009(void *, int);
};
struct Out { char pad[0x18]; In *p; char q[0]; };
extern "C" void hModuleVariable__assign(Out *arg0, int arg1) {
    arg0->p->v009((char *)arg0 + 0x14, arg1);
}
