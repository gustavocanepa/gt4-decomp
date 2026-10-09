struct Info { int w[16]; };
extern void func_004458D0(void *, int, struct Info *);
int func_00445AB8(void *a, int b)
{
    struct Info info;
    func_004458D0(a, b, &info);
    return info.w[9] & 0xFFFFFF;
}
