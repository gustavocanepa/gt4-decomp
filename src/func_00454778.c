struct E { int a; int b; };
int func_00454778(struct E *p) {
    struct E *q = p;
    while (q->a != 0) q++;
    return q - p;
}
