struct S { char pad[0x928]; int v[1]; };
void func_005FB9D0(struct S *s, int i, int x) { int *e = s->v + i; *e = x; }
