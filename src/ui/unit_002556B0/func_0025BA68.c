struct C { char pad[0x34]; int f34; };
extern void func_0025BCF0(struct C *, int *, float *, float *, int, int);
void func_0025BA68(struct C *c, float x, float y)
{
    func_0025BCF0(c, &c->f34, &x, &y, 0, 0);
}
