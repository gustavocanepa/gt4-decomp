typedef int s32;

extern "C" void func_00451110(s32 arg0, void *arg1);

extern "C" void func_004511E0(s32 arg0) {
    int sp[4];
    sp[0] = arg0;
    func_00451110(arg0, sp);
}
