typedef int s32;

struct Q { s32 a, b, c, d; };
extern "C" void func_004AE440(void *, s32, s32, Q *, s32);

extern "C" void *func_004AE370(void *self, s32 x, s32 y, s32 z) {
    Q q;
    q.a = 0;
    q.b = 0;
    q.c = 0;
    q.d = 0;
    func_004AE440(self, x, y, &q, z);
    return self;
}
