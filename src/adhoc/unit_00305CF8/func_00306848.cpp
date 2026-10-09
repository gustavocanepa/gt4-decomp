typedef int s32;

extern void func_0032E6F8(void *, void *, void *, void *);
extern void func_003065F0(void *, void *);
extern void func_0032E448(void *, s32);
extern char D_00306840[];

void func_00306848(void *arg0, void *arg1, void *arg2, void *arg3)
{
    char buf[0x10];

    if (arg2 == 0) {
        arg2 = D_00306840;
    }
    if (arg3 == 0) {
        arg3 = D_00306840;
    }

    func_0032E6F8(buf, arg1, arg2, arg3);
    func_003065F0(arg0, buf);
    func_0032E448(buf, 2);
}
