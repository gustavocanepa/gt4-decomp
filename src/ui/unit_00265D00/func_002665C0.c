struct S { char pad[0x98]; unsigned char f; };
int func_002665C0(struct S *p, unsigned long long m) { return ((p->f >> 4) & m) != 0; }
