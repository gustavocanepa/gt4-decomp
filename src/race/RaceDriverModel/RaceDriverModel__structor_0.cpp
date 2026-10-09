extern "C" void *func_003B05A8(void *arg0);
extern "C" void *HumanModel__structor_0(void *arg0);
extern char RaceDriverModel__vtable[];

extern "C" void *RaceDriverModel__structor_0(void *arg0)
{
    void *s0 = arg0;
    HumanModel__structor_0(s0);
    *(void **)((char *)s0 + 0x7DC) = RaceDriverModel__vtable;
    return func_003B05A8((char *)s0 + 0x7E0);
}
