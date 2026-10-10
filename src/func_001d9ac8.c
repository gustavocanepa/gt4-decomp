struct S { char pad[0xd8]; int a; char pad2[0x2c]; int b; };
int func_001D9AC8(struct S *s) {
    if (s->a != 0) return 1;
    return s->b;
}
