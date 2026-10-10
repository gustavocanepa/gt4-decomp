struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, float);
};

struct CameraBase {
    VEntry *vt;
};

extern "C" void func_004A53F8(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(void *target);
extern "C" void func_004A5400(void);

extern "C" void CameraBase__virtual_07(CameraBase *self, void *target, float t)
{
    func_004A53F8();
    func_004A7454();
    VEntry *e = &self->vt[3];
    e->fn((char *)self + e->delta, t);
    func_004A7550(target);
    func_004A5400();
}
