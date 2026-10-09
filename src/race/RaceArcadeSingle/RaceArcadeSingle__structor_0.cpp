extern "C" void *RaceArcade__structor_0(void *arg0);
extern "C" char RaceArcadeSingle__vtable[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void RaceArcadeSingle__structor_0(void *arg0)
{
    RaceArcade__structor_0(arg0);
    ((S003F15B0 *)arg0)->unk64 = RaceArcadeSingle__vtable;
}
