typedef int s32;

struct Obj {
    char pad[0x958];
    s32 unk958;
};

extern "C" void RaceBase__virtual_60(void *arg0);

extern "C" void RaceFreeRun__virtual_60(void *arg0, struct Obj *arg1) {
    RaceBase__virtual_60(arg0);
    arg1->unk958 = 1;
}
