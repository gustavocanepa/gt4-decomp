extern "C" void *func_003B05A8(void *arg0);
extern "C" void *HumanModel__structor_0(void *arg0);
extern char RaceDriverModel__vtable[];

struct RaceDriverModel__structor_0_s0 {
    char pad0[0x7DC];
    void *unk7DC;
};

extern "C" void *RaceDriverModel__structor_0(void *arg0)
{
    void *s0 = arg0;
    HumanModel__structor_0(s0);
    ((struct RaceDriverModel__structor_0_s0 *)s0)->unk7DC = RaceDriverModel__vtable;
    return func_003B05A8((char *)s0 + 0x7E0);
}
