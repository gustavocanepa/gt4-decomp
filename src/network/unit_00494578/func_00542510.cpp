/* Stores the object's accumulated line in the first free slot: trims leading and trailing blanks,
   copies the text into a fresh buffer, then empties the line. The leading-blank test reads the char
   through r (the int later holding the result), and r = *p after the loop; both keep retail's registers. */
struct Obj {
    char pad0[0x8414];
    char buf[0x8C14 - 0x8414];
    int len;
};
struct Slots { char pad[0xC]; char *slot[0x40]; };
extern "C" int func_0057F260(const char *);
extern "C" int func_00541208(Obj *, char **, int);
extern "C" char *func_005A609C(char *, const char *);

extern "C" int func_00542510(Obj *o, Slots *s) {
    char *p = o->buf;
    char *q;
    unsigned int i;
    int r;
    if (s == 0)
        return 2;
    if (o == 0)
        return 2;
    o->buf[o->len] = 0;
    if (*p) {
        do {
            r = *p;
            if (r == ' ' || r == '\t' || r == '\r' || *p == '\n')
                p++;
            else
                break;
        } while (*p);
        r = *p;
    }
    q = &o->buf[o->len - 1];
    if (p < q) {
        do {
            if (*q == ' ' || *q == '\t' || *q == '\r' || *q == '\n') {
                *q = 0;
                q--;
            } else
                break;
        } while (p < q);
    }
    for (i = 0; i < 0x40; i++) {
        if (s->slot[i] == 0) {
            r = func_00541208(o, &s->slot[i], func_0057F260(p) + 1);
            if (r != 0)
                return r;
            func_005A609C(s->slot[i], p);
            break;
        }
    }
    o->buf[0] = 0;
    o->len = 0;
    return 0;
}
