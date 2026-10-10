typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct M3 { u128 r[3]; };
extern "C" void func_00487450(void *, M3 *);

extern "C" M3 *func_00421C58(M3 *out, void *src) {
    M3 t;
    func_00487450(src, &t);
    out->r[0] = t.r[0];
    out->r[1] = t.r[1];
    out->r[2] = t.r[2];
    return out;
}
