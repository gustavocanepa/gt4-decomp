typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_0044EA58(void);
extern "C" void func_0044EB10(void *self, s32 x, void (*cb)(void), Pair *p);

extern "C" void func_0044EAC8(void *self, s32 a, s32 b, s32 x) {
    if (a || b) {
        Pair p;
        p.a = a;
        p.b = b;
        func_0044EB10(self, x, func_0044EA58, &p);
    }
}
