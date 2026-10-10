struct Obj {
    int m0;
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08();
    virtual void set(int value);
};

/* A handle class named after its destructor (func_00273CA0) so that _$_13func_00273CA0
   resolves; its constructor (func_002740E0) is called explicitly. */
struct func_00273CA0 {
    Obj *p;
    ~func_00273CA0();
};

extern "C" void func_002740E0(func_00273CA0 *h);

/* The result class, named after its constructor so that __13func_0021D810... resolves. */
struct func_0021D810 {
    int m0;
    func_0021D810(func_00273CA0 *h);
    func_0021D810(const func_0021D810 &o);
};

func_0021D810 func_00218A60(int value)
{
    func_00273CA0 h;
    func_002740E0(&h);
    h.p->set(value);
    return func_0021D810(&h);
}
