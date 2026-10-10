extern "C" int func_00427778(int);
extern "C" void func_00427FE8(void *self, int a, float b, float c, float d, float e, int f, float g);

extern "C" void func_004280A8(void *self, int unused, float b, float c, float d, float e, int f, float g) {
    int p = *(int *)((char *)self + 4);
    if (p != 0) {
        func_00427FE8(self, func_00427778(p), b, c, d, e, f, g);
    }
}
