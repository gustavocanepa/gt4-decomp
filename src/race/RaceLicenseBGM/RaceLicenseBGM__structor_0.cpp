extern "C" void *RaceBGMPS2__structor_0(void *arg0);
extern "C" char RaceLicenseBGM__vtable[];

extern "C" void RaceLicenseBGM__structor_0(void *arg0)
{
    RaceBGMPS2__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = RaceLicenseBGM__vtable;
    *(int *)((char *)arg0 + 0x11E8) = 0;
}
