struct P { char pad[0xC]; int c; };
struct S { char pad[0x44]; struct P *p; };
void func_0053DD38(struct S *a, int b) {
    if (a) {
        if (b == 0) a->p->c = 2;
        else a->p->c = 8;
    }
}
