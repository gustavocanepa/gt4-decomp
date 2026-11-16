/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void mComposite__deepCopy(void *, void *);
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern char mScrollWindow__tf[];
extern char hObject__tf[];
struct Entry { short delta; short index; void *fn; };
extern "C" void mScrollWindow__virtual_08(char *self, char *src) {
    mComposite__deepCopy(self, src);
    char *p = 0;
    if (src) {
        Entry *e = *(Entry **)(src + 4);
        p = (char *)__dynamic_cast_2(e->fn, mScrollWindow__tf, 0, src + e->delta, hObject__tf, src);
    }
    if (p) {
        *(float *)(self + 0xB4) = *(float *)(p + 0xB4);
        *(int *)(self + 0xB8) = *(int *)(p + 0xB8);
    }
}
