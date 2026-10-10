struct S { char pad[0x28]; struct P { char pad[0x10]; int v; } *p; };
extern "C" void func_001FCA80(S *, int);
extern "C" void func_0021CF28(S *s) {
    if (s->p) return func_001FCA80(s, s->p->v);
    func_001FCA80(s, 0);
}
