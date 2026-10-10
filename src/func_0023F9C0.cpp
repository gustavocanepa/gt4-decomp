struct Obj_0023F9C0 {
    char pad[0x10];
    void *unk10;
};

extern "C" double func_0057FB50(float x);
extern "C" double func_0057F768(double a, double b);
extern "C" float func_0057FA48(double x);
extern "C" void func_002C3C70(void *arg0, float arg1);

extern "C" void func_0023F9C0(Obj_0023F9C0 *arg0, float arg1) {
    float r = func_0057FA48(func_0057F768(1.0, func_0057FB50(arg1 * 60.0f)));
    func_002C3C70(arg0->unk10, r);
}
