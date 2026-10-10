struct S { int a; float f; };
int func_00375E48(struct S *s, float x) {
    if (s->a < 0) return 1;
    return s->f <= x;
}
