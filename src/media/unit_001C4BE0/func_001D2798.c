struct S { char pad[0x674]; int a; char pad2[0x14]; int b; int c; char pad3[0x38]; int d; };
int func_001D2798(struct S *s) {
    if (s->c == 0) return 0;
    if (s->d != 0 && s->b != 0) return s->a;
    return -1;
}
