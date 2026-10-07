struct C { char pad[0x34]; int f34; };
extern void func_0025B730(struct C *, int *, float *, float *, int, int);
void func_0025B2E0(struct C *c, float y)
{
    func_0025B730(c, &c->f34, &y, 0, 0, 0);
}
