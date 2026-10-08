typedef int s32;

extern "C" s32 func_00444190(s32 arg0);
extern "C" char D_0067FC10[];

extern "C" void func_003B4A98(void *arg0)
{
    func_00444190((s32)arg0);
    *(int *)((char *)arg0 + 0x178) = 0;
    *(void **)((char *)arg0 + 0x17C) = D_0067FC10;
}
