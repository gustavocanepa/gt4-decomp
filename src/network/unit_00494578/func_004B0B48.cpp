struct Info {
    int err;
    int a;
    int b;
    int c;
    int d;
};

struct Result {
    Info info;
    int extra;
};

struct Arg {
    char pad[0x84];
    Info info;
    char pad98[0xC];
    int extra;
};

struct ObjData { char pad[0xA4]; };
struct Obj : ObjData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual Result query(Arg *arg);
};

extern "C" int func_004B0B48(Obj *o, Arg *arg) {
    Result r = o->query(arg);
    if (r.info.err != 0) {
        arg->info.err = r.info.err;
        return 0;
    }
    arg->info = r.info;
    arg->extra = r.extra;
    return 1;
}
