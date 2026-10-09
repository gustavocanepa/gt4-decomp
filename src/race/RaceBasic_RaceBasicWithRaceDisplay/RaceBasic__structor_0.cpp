typedef int s32;

extern void *RaceBasic__vtable;
extern "C" void *RacePS2Base__structor_0(void *);

extern "C" void *RaceBasic__structor_0(void *arg0) {
    void *r0 = RacePS2Base__structor_0(arg0);
    *(void **)((char *)arg0 + 0xe400) = 0x0;
    *(void **)((char *)arg0 + 0x64) = &RaceBasic__vtable;
    *(void **)((char *)arg0 + 0xe404) = 0x0;
    *(void **)((char *)arg0 + 0xe40c) = 0x0;
    *(void **)((char *)arg0 + 0xe414) = 0x0;
    *(void **)((char *)arg0 + 0xe408) = 0x0;
    *(void **)((char *)arg0 + 0xe410) = 0x0;
    *(void **)((char *)arg0 + 0xe418) = 0x0;
    *(void **)((char *)arg0 + 0xe41c) = 0x0;
    *(void **)((char *)arg0 + 0xe420) = 0x0;
    *(void **)((char *)arg0 + 0xe424) = 0x0;
    return r0;
}
