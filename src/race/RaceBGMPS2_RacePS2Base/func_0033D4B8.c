struct Q { char pad[0xCC8]; unsigned st; };
struct P { char pad[0x84]; struct Q *q; };
struct O { struct P *p; char pad[0x30]; int f34; };
struct G { char pad[0x38D1C]; int a; char pad2[0xc]; int b; };
extern struct G *D_00622F4C;
int func_0033D4B8(struct O *o) {
    int v;
    int c = o->p->q->st >= 2u;
    if (c) {
        v = D_00622F4C->b;
        if (o->f34 != 0) return v ^ 1;
    } else {
        v = D_00622F4C->a;
    }
    return v;
}
