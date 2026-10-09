/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int a0, a4, a8, aC, a10, a14, a18, a1C;
    float f20, f24;
    int a28, a2C, a30, a34, a38;
};
extern "C" Obj *func_00105378(Obj *d, const Obj *s) {
    d->a0 = s->a0; d->a4 = s->a4; d->a8 = s->a8; d->aC = s->aC;
    d->a10 = s->a10; d->a14 = s->a14; d->a18 = s->a18; d->a1C = s->a1C;
    d->f20 = s->f20; d->f24 = s->f24;
    d->a28 = s->a28; d->a2C = s->a2C; d->a30 = s->a30;

    d->a38 = s->a38; d->a34 = 0;
    return d;
}
