struct C { char pad[0x34]; int f34; };
extern void func_0025BCF0(struct C *, int *, float *, float *, int, int);
void func_0025B9A8(struct C *c, float y)
{
    func_0025BCF0(c, &c->f34, &y, 0, 0, 0);
}
