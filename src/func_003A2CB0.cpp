typedef int s32;

struct Target_003A2CB0 {
    virtual void v01();
    virtual void v02();
    virtual void v03(int a);
};

struct Base_003A2CB0 {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v24();
    virtual Target_003A2CB0 *v25(int a);
};

struct Obj_003A2CB0 : Base_003A2CB0 {
    int m4;
};

extern "C" void func_003A2CB0(Obj_003A2CB0 *arg0, s32 arg1) {
    arg0->v25(arg0->m4)->v03(arg1);
}
