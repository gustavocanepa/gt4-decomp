/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x, y, z, w;
    V() {}
    V(const V &o) { *(u128 *)this = *(const u128 *)&o; }
} __attribute__((aligned(16)));
struct Obj { V pos; V a; V b; V c; };
extern "C" V func_00421E50(V *a, V *b);
extern "C" V func_0041B898(Obj *o) {
    V r = func_00421E50(&o->a, &o->c);
    r.x += o->pos.x;
    r.y += o->pos.y;
    r.z += o->pos.z;
    return r;
}
