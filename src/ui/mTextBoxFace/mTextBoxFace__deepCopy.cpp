/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void mScrollable__deepCopy(void *, void *);
extern "C" void func_00248398(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern char mTextBoxFace__tf[], hObject__tf[];
struct Entry { short delta; short index; void *fn; };
struct Obj { int x; Entry *vt; };
extern "C" void mTextBoxFace__deepCopy(char *self, Obj *src) {
    mScrollable__deepCopy(self, src);
    char *p = 0;
    if (src) {
        Entry *e = src->vt;
        p = (char *)__dynamic_cast_2(e->fn, mTextBoxFace__tf, 0, (char *)src + e->delta, hObject__tf, src);
    }
    if (p) func_00248398(self + 0xC0, p + 0xC0);
}
