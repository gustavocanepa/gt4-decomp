struct S { char pad[0x774]; int f; };
extern void func_00557E68(struct S *, int);
void func_00557E38(struct S *s) {
    func_00557E68(s, 0);
    s->f = 1;
}
