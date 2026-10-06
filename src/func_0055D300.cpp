extern "C" void func_0055C9A0(int val, int *ptr, int addr, int *stack_data, int arg4);

extern "C" int D_0055CE88;

extern "C" void func_0055D300(int *arg0, int arg1, int arg2) {
    int buf[2];
    buf[0] = arg1;
    buf[1] = arg2;
    func_0055C9A0(*arg0, arg0, (int)&D_0055CE88, buf, 0);
}
