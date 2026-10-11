extern "C" void free(int arg);
extern "C" void func_005C1628(void *arg);

extern "C" void func_004EE848(void *arg0, int arg1) {
    free(*(int*)arg0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
