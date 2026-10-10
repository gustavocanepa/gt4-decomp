struct In {
    char pad[0xC];
    virtual int v00(); virtual int v01();
};
extern "C" In *func_00436F20(int);
extern "C" int func_0018FCC8(char *arg0) {
    In *o = func_00436F20(*(int *)(arg0 + 0x10));
    return o->v01();
}
