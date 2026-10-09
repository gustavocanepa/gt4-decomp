typedef int s32;

extern "C" s32 func_00444190(s32 arg0);
extern "C" char RaceEntryInformation__vtable[];

extern "C" void RaceEntryInformation__structor_0(void *arg0)
{
    func_00444190((s32)arg0);
    *(int *)((char *)arg0 + 0x178) = 0;
    *(void **)((char *)arg0 + 0x17C) = RaceEntryInformation__vtable;
}
