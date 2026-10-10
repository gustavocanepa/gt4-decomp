struct Buf { int active; int len; char buf[0x400]; };

extern "C" int func_0026CAE0(Buf *b, const char *s, int n)
{
    if (!b->active) return 1;
    for (int i = 0; i < n; i++) {
        if (b->len >= 0x3FF) { b->buf[0x3FF] = 0; return 0; }
        b->buf[b->len] = s[i];
        b->len++;
    }
    b->buf[b->len] = 0;
    return 1;
}
