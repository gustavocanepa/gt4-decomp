extern "C" int func_00427778(int);
extern "C" void func_00428C00(void *self, int a, int b, float c, int d, int e, float f);

extern "C" void func_00428CB8(void *self, int unused, int b, float c, int d, int e, float f) {
    int p = *(int *)((char *)self + 4);
    if (p != 0) {
        func_00428C00(self, func_00427778(p), b, c, d, e, f);
    }
}
