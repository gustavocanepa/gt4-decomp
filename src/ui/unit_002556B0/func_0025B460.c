struct C { char pad[0x34]; int f34; };
extern void func_0025B730(struct C *, int *, float *, float *, int, int);
void func_0025B460(struct C *c, float x, float y)
{
    func_0025B730(c, &c->f34, &x, &y, 0, 0);
}
