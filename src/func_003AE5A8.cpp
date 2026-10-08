extern "C" void *func_003A49A0(void *arg0);
extern "C" char D_0067E820[];

extern "C" void func_003AE5A8(void *arg0)
{
    func_003A49A0(arg0);
    *(int *)((char *)arg0 + 0x154) = 0;
    *(int *)((char *)arg0 + 0x150) = 0;
    *(void **)((char *)arg0 + 0x14) = D_0067E820;
}
