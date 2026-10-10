/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct {
    int m0;
    void *m4;
    char *m8;
    char *mC;
    int m10;
    int m14;
} Req_0055A1F8;

char *func_00559B10(void *a, void *b);

void func_0055A1F8(Req_0055A1F8 *r, void *a, void *b, int unused, int n) {
    char *p;
    r->m0 = 0;
    r->m4 = a;
    p = func_00559B10(a, b);
    r->m8 = p;
    r->mC = p ? p + 8 : 0;
    r->m10 = n;
    r->m14 = 2;
}
