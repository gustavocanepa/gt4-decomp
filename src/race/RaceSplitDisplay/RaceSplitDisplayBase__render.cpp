struct Child {
    virtual void s1(int v);
    virtual void s2(int v);
    virtual void apply(int v);
    virtual void s4(int v);
    virtual void s5(int v);
    virtual void s6(int v);
    virtual void s7(int v);
    virtual void s8(int v);
};

struct Obj {
    virtual void v00();
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
    virtual Child *child(int i);
    void method(int v) __asm__("RaceSplitDisplayBase__render");
};

void Obj::method(int v) {
    for (int i = 0; i < 2; i++)
        child(i)->apply(v);
}
