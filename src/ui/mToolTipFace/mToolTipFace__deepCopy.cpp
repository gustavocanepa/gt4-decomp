/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TypeInfo { short delta; short pad; void *fn; };
struct Object { int x; TypeInfo *type; };
extern char mToolTipFace__tf[], hObject__tf[];
extern "C" void mWidget__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void func_00248398(void *, void *);
extern "C" void mToolTipFace__deepCopy(char *dst, Object *src) {
    mWidget__deepCopy(dst, src);
    char *p = 0;
    if (src) {
        TypeInfo *t = src->type;
        p = (char *)__dynamic_cast_2(t->fn, mToolTipFace__tf, 0, (char *)src + t->delta, hObject__tf, src);
    }
    if (p) func_00248398(dst + 0xa0, p + 0xa0);
}
