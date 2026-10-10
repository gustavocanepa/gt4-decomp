typedef int s32;

struct Quad { s32 a, b, c, d; };
struct Info { char pad[0x24]; Quad q; char pad34[0xC]; };
extern "C" s32 func_004458D0(void *, s32, Info *);

extern "C" s32 func_00445B28(void *self, s32 key, Quad *out) {
    Info info;
    if (!func_004458D0(self, key, &info))
        return 0;
    out->a = info.q.a;
    out->b = info.q.b;
    out->c = info.q.c;
    out->d = info.q.d;
    return 1;
}
