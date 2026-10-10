struct In {
    char pad[0x5c];
    virtual int v00();
    virtual int v01();
    virtual int v02();
};
struct Out { char pad[0x58]; In *p; };
extern "C" int func_0047D938(Out *arg0) {
    return arg0->p->v02();
}
