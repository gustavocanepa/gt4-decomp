typedef int s32;

class hObject {
public:
    s32 ref;
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
    virtual s32 getInt();
};

extern "C" void func_0013BDC0(void *);
extern "C" s32 func_00147D80(s32);
extern "C" void func_0013BD68(void *, s32);
extern "C" void func_0043E3C0(s32, s32);
extern "C" void func_0043E3E8(s32, s32);

extern "C" void MCarGarage__setBrakeControllerSetting(s32 *arg0, void *arg1, s32 arg2, hObject **arg3) {
    s32 buf[4];
    s32 garage;
    s32 value;
    s32 kind;

    func_0013BDC0(buf);
    garage = func_00147D80(buf[0]);
    func_0013BD68(buf, 2);
    value = arg3[1]->getInt();
    kind = arg3[0]->getInt();
    switch (kind) {
    case 0:
        func_0043E3C0(garage, value);
        break;
    case 1:
        func_0043E3E8(garage, value);
        break;
    }
}
