struct A { char pad[0x18]; void *res; };
extern void free(void *);
void func_003951D0(struct A *a)
{
    free(a->res);
    a->res = 0;
}
