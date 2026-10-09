extern "C" void *RaceInput__structor_0(void *arg0);
extern "C" char RaceInputLan__vtable[];

struct S00335C80 {
    char pad[0xD0];
    void *unkD0;
};

extern "C" void RaceInputLan__structor_0(struct S00335C80 *arg0)
{
    RaceInput__structor_0(arg0);
    arg0->unkD0 = RaceInputLan__vtable;
}
