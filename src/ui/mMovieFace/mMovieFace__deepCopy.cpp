/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *fn; };
struct Obj { int x; Entry *vt; };
extern char mMovieFace__tf[], hObject__tf[];
extern "C" void mImageFace__deepCopy(void *, void *);
extern "C" void *func_002212C8(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void mMovieFace__deepCopy(char *self, Obj *src) {
    mImageFace__deepCopy(self, src);
    char *p = 0;
    if (src) {
        Entry *e = src->vt;
        p = (char *)__dynamic_cast_2(e->fn, mMovieFace__tf, 0, (char *)src + e->delta, hObject__tf, src);
    }
    if (p) func_002212C8(self + 0xF0, p + 0xF0);
}
