struct Joint;

struct Obj {
    char pad[0x7C];
    char springs[0xC];
    float strength;
};

extern "C" void DynamicsConductor__ComputeDifference(Obj *o, Joint *a, Joint *b, int *ival, float *fval);
extern "C" void func_00365560(void *springs, Joint *a, Joint *b, int ival, float fval);

extern "C" void func_003655F8(Obj *o, Joint *a, Joint *b) {
    int iv;
    float fv;
    if (o->strength == 0.0f)
        return;
    DynamicsConductor__ComputeDifference(o, a, b, &iv, &fv);
    func_00365560(o->springs, a, b, iv, fv);
    func_00365560(o->springs, b, a, -iv, -fv);
}
