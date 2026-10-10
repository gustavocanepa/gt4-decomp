struct S { char pad[0x170]; int a; int b; };
int func_003EF330(struct S *p) { int lt = p->a < p->b; if (lt == 0) return 1; return 0; }
