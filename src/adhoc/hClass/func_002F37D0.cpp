extern "C" int HSymID__GetID(int arg1);
extern "C" void func_002F36A0(void *arg0, int *arg1, void *arg2);

extern "C" void func_002F37D0(void *arg0, int arg1, void *arg2) {
    void *s1 = arg0;
    void *s0 = arg2;
    int local = HSymID__GetID(arg1);
    func_002F36A0(s1, &local, s0);
}
