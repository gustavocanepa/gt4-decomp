struct Obj {
    virtual void v0();
    virtual void update(float t);
};

extern "C" void func_004A53F8(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(void *x);
extern "C" void func_004A5400(void);

extern "C" void CameraBase__getProjectionMatrix(Obj *o, void *x, float t) {
    func_004A53F8();
    func_004A7454();
    o->update(t);
    func_004A7550(x);
    func_004A5400();
}
