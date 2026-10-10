/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Mgr_004AF910 {
    char pad0[0xA4];
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
    virtual s32 v23(void *a, s32 b);
};

extern "C" Mgr_004AF910 *func_004AFA78(void);

extern "C" s32 func_004AF910(void *arg0, s32 arg1) {
    return func_004AFA78()->v23(arg0, arg1);
}
