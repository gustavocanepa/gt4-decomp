extern "C" int func_0025C2A0(int arg0);
extern "C" int func_00265D98(int arg0);
extern "C" void func_002661D8(void);

extern "C" void func_00266200(int arg0, int arg1) {
    int s0 = arg0;
    int s1 = arg1;
    func_002661D8();
    if (func_00265D98(s0) != 0) {
        if (func_0025C2A0(s0) != 0) {
            func_00266200(func_0025C2A0(s0), s1);
        }
    }
}
