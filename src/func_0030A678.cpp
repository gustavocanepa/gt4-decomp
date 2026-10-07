extern "C" void *func_00328420(void *arg0);
extern "C" char D_00674F30[];

extern "C" void func_0030A678(void *arg0)
{
    func_00328420(arg0);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_00674F30;
}
