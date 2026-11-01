/* Updates a packed 4-bit state word (mode, a, b) for mode `want`: mode 0 takes
   want and val, modes 1-3 set b and lower a; returns 1 when a changed. ref()
   puts cur and want in stack slots (reloaded at sp+0/sp+4 like the original),
   and the three identical cases keep the ==1,<2,==2,==3 tree (no range test). */
struct Bits {
    unsigned int mode : 4;
    unsigned int a : 4;
    unsigned int b : 4;
};

static inline const int &ref(const int &x) { return x; }

extern "C" int func_00430A58(Bits *t, int want, unsigned char val) {
    int cur = t->mode;
    int r;
    if (ref(cur) != 0 && ref(want) != ref(cur)) return 0;
    r = 0;
    switch (cur) {
    case 0:
        t->mode = want;
        t->a = val;
        t->b = t->a;
        r = 1;
        break;
    case 1:
        t->b = val;
        if ((int)val < (int)t->a) { t->a = val; r = 1; }
        break;
    case 2:
        t->b = val;
        if ((int)val < (int)t->a) { t->a = val; r = 1; }
        break;
    case 3:
        t->b = val;
        if ((int)val < (int)t->a) { t->a = val; r = 1; }
        break;
    }
    return r;
}
