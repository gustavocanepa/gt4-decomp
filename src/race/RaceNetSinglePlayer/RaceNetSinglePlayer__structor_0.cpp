extern "C" void *RaceSinglePlayer__structor_0(void *arg0);
extern "C" char RaceNetSinglePlayer__vtable[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void RaceNetSinglePlayer__structor_0(void *arg0)
{
    RaceSinglePlayer__structor_0(arg0);
    ((S003F15B0 *)arg0)->unk64 = RaceNetSinglePlayer__vtable;
}
