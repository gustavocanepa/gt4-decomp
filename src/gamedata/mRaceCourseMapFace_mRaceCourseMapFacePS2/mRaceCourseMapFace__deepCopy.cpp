/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *fn; };
struct Obj { int x; Entry *vt; };
extern char mRaceCourseMapFace__tf[], hObject__tf[];
extern "C" void mWidget__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void *func_002030E8(void *, void *);
extern "C" void mRaceCourseMapFace__deepCopy(char *self, Obj *src) {
    mWidget__deepCopy(self, src);
    char *p = 0;
    if (src) {
        Entry *e = src->vt;
        p = (char *)__dynamic_cast_2(e->fn, mRaceCourseMapFace__tf, 0, (char *)src + e->delta, hObject__tf, src);
    }
    if (p) {
        func_002030E8(self + 0xa0, p + 0xa0);
        func_002030E8(self + 0xb0, p + 0xb0);
        *(int *)(self + 0xc0) = *(int *)(p + 0xc0);
        *(int *)(self + 0xc4) = *(int *)(p + 0xc4);
    }
}
