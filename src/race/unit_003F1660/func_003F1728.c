extern unsigned char D_006224A8;
struct S { char pad[0x1b8]; unsigned char b; };
int func_003F1728(struct S *t) {
    unsigned char x = t->b;
    if (D_006224A8) x &= 0x3F;
    return x == 0;
}
