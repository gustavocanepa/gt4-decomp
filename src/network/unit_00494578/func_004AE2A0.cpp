typedef int s32;

struct P2 { s32 a, b; };
struct Q { s32 a, b, c, d; };
extern "C" void func_004AE330(void *, s32, Q *, s32);

extern "C" void *func_004AE2A0(void *self, s32 x, P2 *p, s32 y) {
    Q q;
    q.a = p->a;
    q.b = p->b;
    q.c = 0;
    q.d = 0;
    func_004AE330(self, x, &q, y);
    return self;
}
