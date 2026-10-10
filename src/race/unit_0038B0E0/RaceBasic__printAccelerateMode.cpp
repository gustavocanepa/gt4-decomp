struct Widget {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void set(int id, int a, int b);
};

struct PanelData { char pad[0x64]; };
struct Panel : PanelData {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual int state();
};

struct PanelView : Panel {
    char pad68[0xE420 - 0x68];
    Widget *widget;
};

extern int *DisplayRText__rtext_ptrs_;

extern "C" void RaceBasic__printAccelerateMode(PanelView *p) {
    if (p->widget) {
        int idx = p->state() ? 31 : 32;
        p->widget->set(DisplayRText__rtext_ptrs_[idx], 0, 0);
    }
}
