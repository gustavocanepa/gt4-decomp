struct Obj {
    char pad[0x64];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void *v25(int i);
};
extern "C" void func_00374418(void *node);
extern "C" void func_00374470(void *node);

extern "C" void func_0010B9C8(Obj *o, int on)
{
    void *node = o->v25(0);
    if (on)
        return func_00374418(node);
    func_00374470(node);
}
