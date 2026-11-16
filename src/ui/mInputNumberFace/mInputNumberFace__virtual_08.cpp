/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void *fn; };
struct Data { int a,b,c,d,e; };
struct Obj { int head; Entry *vt; char pad[0x100]; Data data; };
extern "C" void mWidget__deepCopy(Obj *, const Obj *);
extern "C" Obj *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern char mInputNumberFace__tf[], hObject__tf[];
static inline Obj *cast(Obj *p) {
    if (!p) return 0;
    Entry *v = p->vt;
    return __dynamic_cast_2(v->fn,mInputNumberFace__tf,0,(char *)p+v->delta,hObject__tf,p);
}
extern "C" void mInputNumberFace__virtual_08(Obj *o, Obj *p) {
    mWidget__deepCopy(o,p);
    Obj *q = cast(p);
    if (q) {
        Data *src = &q->data;
        Data *dst = &o->data;
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
        dst->e = src->e;
    }
}
