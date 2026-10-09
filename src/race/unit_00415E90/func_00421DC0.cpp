/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x, y, z, w;
    V() {}
    V(const V &o) { *(u128 *)this = *(const u128 *)&o; }
} __attribute__((aligned(16)));
extern "C" void func_00487390(int a, V *out);
extern "C" V func_00421DC0(int a) {
    V r;
    func_00487390(a, &r);
    return r;
}
