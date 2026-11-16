/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *fn; };
struct Obj { int x; Entry *vt; };
extern char mCarFace__tf[], hObject__tf[];
extern "C" void mWidget__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void *func_0021BDB8(void *, void *);
extern "C" void *func_002024F0(void *, void *);
extern "C" void func_00211208(void *, void *);
extern "C" void mCarFace__deepCopy(char *self, Obj *src) {
    mWidget__deepCopy(self, src);
    char *p = 0;
    if (src) {
        Entry *e = src->vt;
        p = (char *)__dynamic_cast_2(e->fn, mCarFace__tf, 0, (char *)src + e->delta, hObject__tf, src);
    }
    if (p) {
        func_0021BDB8(self + 0xa0, p + 0xa0);
        func_002024F0(self + 0xd0, p + 0xd0);
        func_00211208(self + 0x138, p + 0x138);
    }
}
