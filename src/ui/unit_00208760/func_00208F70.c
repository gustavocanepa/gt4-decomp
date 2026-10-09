struct Q { int a, b, c, d; };
extern void func_00309348(void *, struct Q *);
extern void func_00208FB8(void *, int);
void func_00208F70(void *p, int v)
{
    struct Q q;
    q.a = 0;
    func_00309348(p, &q);
    func_00208FB8(p, v);
}
