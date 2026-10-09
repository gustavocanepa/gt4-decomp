extern "C" void *func_00104048(void *arg0);
extern char D_00659C50[];

extern "C" void func_00104D28(void *arg0)
{
    func_00104048(arg0);
    *(int *)((char *)arg0 + 0x30) = 0;
    *(void **)((char *)arg0 + 0x0) = D_00659C50;
}
