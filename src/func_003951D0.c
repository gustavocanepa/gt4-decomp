struct A { char pad[0x18]; void *res; };
extern void func_00575DA0(void *);
void func_003951D0(struct A *a)
{
    func_00575DA0(a->res);
    a->res = 0;
}
