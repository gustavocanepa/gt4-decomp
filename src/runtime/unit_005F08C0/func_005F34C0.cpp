struct In {
    char pad[0xd0];
    virtual void v000(char *);
    virtual void v001(char *);
    virtual void v002(char *);
    virtual void v003(char *);
    virtual void v004(char *);
    virtual void v005(char *);
};
extern "C" void func_005F34C0(char *arg0, In *arg1) {
    arg1->v005(arg0 + 0x204);
}
