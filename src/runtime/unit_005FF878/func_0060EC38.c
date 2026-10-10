struct R { int pad; unsigned pos; int count; };
void func_0060EC38(struct R *s, int n) {
    unsigned p = s->pos + n;
    if (p >= 0x100) p -= 0x100;
    s->count -= n;
    s->pos = p;
}
